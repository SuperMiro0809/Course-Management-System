#include "GradeAssignmentCommand.h"

#include "../services/CoursesDatabase.h"
#include "../services/CourseAssignmentsDatabase.h"
#include "../services/AssigmentSubmissionsDatabase.h"
#include "../services/MessagesDatabase.h"

GradeAssignmentCommand::GradeAssignmentCommand(
    const String& courseName,
    const String& assignmentName,
    unsigned int studentId,
    double grade,
    const String& message
): courseName(courseName), assignmentName(assignmentName), studentId(studentId), grade(grade), message(message) {}

void GradeAssignmentCommand::execute(System& system) {
    const User* currUser = system.getCurrentUser();

    if (!currUser || currUser->getRole() != "Teacher") {
        throw std::logic_error("Command forbidden!");
    }

    CoursesDatabase coursesDb("../courses.txt");
    const Course* course = coursesDb.findCourseByName(courseName);

    if (!course) {
        throw std::logic_error("Course does not exist!");
    }

    if (course->getCreatorId() != currUser->getId()) {
        throw std::logic_error("You do not have permissions for this course!");
    }

    unsigned int courseId = course->getId();
    delete course;

    CourseAssignmentsDatabase courseAssignmentsDb("../course_assignments.txt");
    unsigned int assigmentId = courseAssignmentsDb.findCourseAssigment(courseId, assignmentName);

    if (assigmentId == 0) {
        throw std::logic_error("Assigment not found.");
    }

    AssigmentSubmissionsDatabase assignmentSubmissionsDb("../course_assignment_submissions.txt");

    SubmissionsContainer submissions = assignmentSubmissionsDb.getAssignmentSubmissions(assigmentId);
    size_t count = submissions.getSubmissionsCount();
    bool isGraded = false;

    for (size_t i = 0; i < count; i++) {
        Submission s = submissions[i];
        unsigned int currStudentId = s.getStudentId();

        if (currStudentId == studentId) {
            s.addGrade(grade, message);
            isGraded = true;

            MessagesDatabase messagesDb("../messages.txt");
            String messageStr =  currUser->getFirstName() + " " + currUser->getFamilyName() + " graded your work on " + assignmentName + " in " + courseName;
            messagesDb.sendMessage(currUser->getId(), currStudentId, messageStr);
            break;
        }
    }

    if (!isGraded) {
        throw std::logic_error("This student has no submission in this assignment.");
    }
}