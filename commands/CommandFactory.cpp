#include "CommandFactory.h"

#include "sstream"
#include "../utils/String.h"
#include "LoginCommand.h"
#include "LogoutCommand.h"
#include "AddTeacherCommand.h"

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
    }

    return nullptr;
}
