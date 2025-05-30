/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#include "ViewAssignmentSubmissions.h"

#include "../models/Course.h"
#include "../services/CoursesDatabase.h"
#include "../services/CourseStudentsDatabase.h"
#include "../services/CourseAssignmentsDatabase.h"
#include "../services/AssigmentSubmissionsDatabase.h"
#include "../utils/SubmissionsContainer.h"

ViewAssignmentSubmissions::ViewAssignmentSubmissions(const String& courseName, const String& assignmentName):
    courseName(courseName),
    assignmentName(assignmentName) {}

void ViewAssignmentSubmissions::execute(System& system) {
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
    std::cout << submissions;
}