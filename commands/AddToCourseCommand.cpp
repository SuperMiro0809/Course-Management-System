#include "AddToCourseCommand.h"

#include "../services/UsersDatabase.h"
#include "../services/CoursesDatabase.h"
#include "../services/CourseStudentsDatabase.h"
#include "../services/MessagesDatabase.h"
#include "../models/User.h"

AddToCourseCommand::AddToCourseCommand(const String& courseName, unsigned int studentId):
    courseName(courseName),
    studentId(studentId) {}

void AddToCourseCommand::execute(System& system) {
    const User* currUser = system.getCurrentUser();

    if (!currUser || currUser->getRole() != "Teacher") {
        throw std::logic_error("Command forbidden!");
    }

    CoursesDatabase coursesDb("../courses.txt");
    unsigned int courseId = coursesDb.findCreatorCourse(courseName, currUser->getId());

    if (courseId == 0) {
        throw std::logic_error("Course not found or access is denied.");
    }

    UsersDatabase usersDb("../users.txt");
    const User* user = usersDb.getUserById(studentId);

    if (!user) {
        throw std::logic_error("User with such ID is not found.");
    }

    if (user->getRole() != "Student") {
        delete user;
        throw std::logic_error("User with such ID is not a Student.");
    }

    CourseStudentsDatabase courseStudentsDb("../course_students.txt");

    if (courseStudentsDb.isStudentAddedToCourse(courseId, studentId)) {
        delete user;
        throw std::logic_error("Student with this ID is already in this course.");
    }

    courseStudentsDb.addNewCourseStudent(courseId, studentId);
    delete user;

    MessagesDatabase messagesDb("../messages.txt");
    String message = currUser->getFirstName() + " " + currUser->getFamilyName() + " added you to " + courseName;
    messagesDb.sendMessage(currUser->getId(), studentId, message);
}
