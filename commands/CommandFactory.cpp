#include "CommandFactory.h"

#include "sstream"
#include "../utils/String.h"
#include "LoginCommand.h"

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
        // TODO
    }

    return nullptr;
}
