#include "ChangePasswordCommand.h"

#include <stdexcept>
#include "../models/User.h"
#include "../services/UsersDatabase.h"

ChangePasswordCommand::ChangePasswordCommand(const String& oldPassword, const String& newPassword)
  : Command(),
    oldPassword(oldPassword),
    newPassword(newPassword) {}

void ChangePasswordCommand::execute(System& system) {
    const User* currUser = system.getCurrentUser();

    if (!currUser) {
        throw std::logic_error("Command forbidden!");
    }

    UsersDatabase usersDb("../users.txt");

    usersDb.changePassword(currUser->getId(), oldPassword, newPassword);
}