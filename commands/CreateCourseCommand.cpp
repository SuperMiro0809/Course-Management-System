/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#include "CreateCourseCommand.h"

#include "../services/CoursesDatabase.h"

CreateCourseCommand::CreateCourseCommand(const String& courseName, const String& coursePassword):
    courseName(courseName),
    coursePassword(coursePassword) {}

void CreateCourseCommand::execute(System& system) {
    const User* currUser = system.getCurrentUser();

    if (!currUser || currUser->getRole() != "Teacher") {
        throw std::logic_error("Command forbidden!");
    }

    CoursesDatabase coursesDb("../courses.txt");

    coursesDb.addNewCourse(courseName, coursePassword, currUser->getId());
}