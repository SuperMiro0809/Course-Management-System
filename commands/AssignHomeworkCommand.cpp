/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#include "AssignHomeworkCommand.h"

#include "../services/CoursesDatabase.h"
#include "../services/CourseAssignmentsDatabase.h"

AssignHomeworkCommand::AssignHomeworkCommand(const String& courseName, const String& homeworkName):
    courseName(courseName),
    homeworkName(homeworkName) {}

void AssignHomeworkCommand::execute(System& system) {
    const User* currUser = system.getCurrentUser();

    if (!currUser || currUser->getRole() != "Teacher") {
        throw std::logic_error("Command forbidden!");
    }

    CoursesDatabase coursesDb("../courses.txt");
    unsigned int courseId = coursesDb.findCreatorCourse(courseName, currUser->getId());

    if (courseId == 0) {
        throw std::logic_error("Course not found or access is denied.");
    }

    CourseAssignmentsDatabase courseAssignmentsDb("../course_assignments.txt");
    courseAssignmentsDb.addNewAssignment(courseId, homeworkName);
};
