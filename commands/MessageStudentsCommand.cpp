/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#include "MessageStudentsCommand.h"

#include "../models/User.h"
#include "../services/CoursesDatabase.h"
#include "../services/CourseStudentsDatabase.h"

MessageStudentsCommand::MessageStudentsCommand(const String& courseName, const String& message):
    courseName(courseName),
    message(message) {}

void MessageStudentsCommand::execute(System& system) {
    const User* currUser = system.getCurrentUser();

    if (!currUser || currUser->getRole() != "Teacher") {
        throw std::logic_error("Command forbidden!");
    }

    CoursesDatabase coursesDb("../courses.txt");
    unsigned int courseId = coursesDb.findCreatorCourse(courseName, currUser->getId());

    if (courseId == 0) {
        throw std::logic_error("Course not found or access is denied.");
    }

    CourseStudentsDatabase courseStudentsDb("../course_students.txt");
    courseStudentsDb.sendCourseMessage(courseId, currUser->getId(), message);
}