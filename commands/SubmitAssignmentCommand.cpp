/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#include "SubmitAssignmentCommand.h"

#include "../models/Course.h"
#include "../services/CoursesDatabase.h"
#include "../services/CourseStudentsDatabase.h"
#include "../services/CourseAssignmentsDatabase.h"
#include "../services/AssigmentSubmissionsDatabase.h"

SubmitAssignmentCommand::SubmitAssignmentCommand(const String& courseName, const String& assignmentName, const String& submission):
    courseName(courseName),
    assignmentName(assignmentName),
    submission(submission) {}

void SubmitAssignmentCommand::execute(System& system) {
    const User* currUser = system.getCurrentUser();

    if (!currUser || currUser->getRole() != "Student") {
        throw std::logic_error("Command forbidden!");
    }

    CoursesDatabase coursesDb("../courses.txt");
    const Course* course = coursesDb.findCourseByName(courseName);

    if (!course) {
        throw std::logic_error("Course does not exist!");
    }

    unsigned int courseId = course->getId();
    delete course;

    CourseStudentsDatabase courseStudentsDb("../course_students.txt");

    if (!courseStudentsDb.isStudentAddedToCourse(courseId, currUser->getId())) {
        throw std::logic_error("You are not part of this course.");
    }

    CourseAssignmentsDatabase courseAssignmentsDb("../course_assignments.txt");
    unsigned int assigmentId = courseAssignmentsDb.findCourseAssigment(courseId, assignmentName);

    if (assigmentId == 0) {
        throw std::logic_error("Assigment not found.");
    }

    AssigmentSubmissionsDatabase assignmentSubmissionsDb("../course_assignment_submissions.txt");

    if (assignmentSubmissionsDb.isAlreadySubmitted(assigmentId, currUser->getId())) {
        throw std::logic_error("Assigment already submitted.");
    }

    assignmentSubmissionsDb.addNewSubmission(assigmentId, currUser->getId(), submission);
}