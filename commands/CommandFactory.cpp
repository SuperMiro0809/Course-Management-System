#include "CommandFactory.h"

#include "sstream"
#include "../utils/String.h"

Command* CommandFactory::create(const String& input) {
    std::stringstream ss(input.getElements());
    String cmd;
    ss >> cmd;

    if (cmd == "login") {
        unsigned int id;
        String password;

        ss >> id;
        ss >> password;
    } else if (cmd == "logout") {
        // TODO
    }

    return nullptr;
}
