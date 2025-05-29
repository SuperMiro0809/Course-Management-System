#include "MessageAllCommand.h"

#include "../models/User.h"
#include "../models/Admin.h"

MessageAllCommand::MessageAllCommand(const String& message): message(message) {}

void MessageAllCommand::execute(System& system) {
    const User* currUser = system.getCurrentUser();

    if (!currUser || currUser->getRole() != "Admin") {
        throw std::logic_error("Command forbidden!");
    }

    if (const Admin* admin = dynamic_cast<const Admin*>(currUser)) {
        admin->messageAllUsers(message);
    }
}
