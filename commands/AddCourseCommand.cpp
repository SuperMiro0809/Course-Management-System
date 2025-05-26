#include "AddCourseCommand.h"

#include "../services/CoursesDatabase.h"

AddCourseCommand::AddCourseCommand(const String& courseName, const String& coursePassword):
    courseName(courseName),
    coursePassword(coursePassword) {}

void AddCourseCommand::execute(System& system) {
    const User* currUser = system.getCurrentUser();

    if (!currUser || currUser->getRole() != "Teacher") {
        throw std::logic_error("Command forbidden!");
    }

    CoursesDatabase coursesDb("../courses.txt");

    coursesDb.addNewCourse(courseName, coursePassword);
}