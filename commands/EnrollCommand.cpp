/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#include "EnrollCommand.h"

#include "../models/Course.h"
#include "../services/CoursesDatabase.h"
#include "../services/CourseStudentsDatabase.h"

EnrollCommand::EnrollCommand(const String& courseName, const String& coursePassword):
    courseName(courseName),
    coursePassword(coursePassword) {}

void EnrollCommand::execute(System& system) {
    const User* currUser = system.getCurrentUser();

    if (!currUser || currUser->getRole() != "Student") {
        throw std::logic_error("Command forbidden!");
    }

    CoursesDatabase coursesDb("../courses.txt");
    const Course* course = coursesDb.findCourseByName(courseName);

    if (!course) {
        throw std::logic_error("Course does not exist!");
    }

    if (course->getPassword() != coursePassword) {
        delete course;
        throw std::logic_error("Password is incorrect!");
    }

    unsigned int courseId = course->getId();
    delete course;

    CourseStudentsDatabase courseStudentsDb("../course_students.txt");

    if (courseStudentsDb.isStudentAddedToCourse(courseId, currUser->getId())) {
        throw std::logic_error("You are already in this course.");
    }

    courseStudentsDb.addNewCourseStudent(courseId, currUser->getId());
    std::cout << "Successfully enrolled in " << courseName << "!" << std::endl;
}