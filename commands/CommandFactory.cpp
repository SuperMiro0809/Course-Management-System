#include "CommandFactory.h"

#include "sstream"
#include "../utils/String.h"
#include "LoginCommand.h"
#include "LogoutCommand.h"
#include "AddTeacherCommand.h"
#include "AddStudentCommand.h"
#include "ChangePasswordCommand.h"
#include "CreateCourseCommand.h"

Command* CommandFactory::create(const String& input) {
    std::stringstream ss(input.getElements());
    String cmd;
    ss >> cmd;

    if (cmd == "login") {
        unsigned int id;
        String password;

        ss >> id;
        ss >> password;

        return new LoginCommand(id, password);
    } else if (cmd == "logout") {
        return new LogoutCommand();
    } else if (cmd == "add_teacher") {
        String firstName, familyName, password;
        ss >> firstName >> familyName >> password;

        return new AddTeacherCommand(firstName, familyName, password);
    } else if (cmd == "add_student") {
        String firstName, familyName, password;
        ss >> firstName >> familyName >> password;

        return new AddStudentCommand(firstName, familyName, password);
    } else if (cmd == "change_password") {
        String oldPassword, newPassword;
        ss >> oldPassword >> newPassword;

        return new ChangePasswordCommand(oldPassword, newPassword);
    } else if (cmd == "create_course") {
        String courseName, coursePassword;
        ss >> courseName >> coursePassword;

        return new CreateCourseCommand(courseName, coursePassword);
    }

    return nullptr;
}
