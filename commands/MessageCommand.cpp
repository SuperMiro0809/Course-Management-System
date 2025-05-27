#include "MessageCommand.h"

#include "../services/UsersDatabase.h"
#include "../services/MessagesDatabase.h"
#include "../models/User.h"

MessageCommand::MessageCommand(unsigned int userId, const String& message):
    userId(userId),
    message(message) {}

void MessageCommand::execute(System& system) {
    const User* currUser = system.getCurrentUser();

    if (!currUser || currUser->getRole() != "Student") {
        throw std::logic_error("Command forbidden!");
    }

    UsersDatabase usersDb("../users.txt");

    const User* user = usersDb.getUserById(userId);
    if (!user) {
        throw std::logic_error("User with that ID does not exist!");
    }

    delete user;
    MessagesDatabase messagesDb("../messages.txt");
    messagesDb.sendMessage(currUser->getId(), userId, message);
}
