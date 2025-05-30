/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#include "LogoutCommand.h"

#include <stdexcept>
#include "../models/User.h"

void LogoutCommand::execute(System& system) {
    const User* currUser = system.getCurrentUser();

    if (!currUser) {
        throw std::logic_error("Command forbidden!");
    }

    system.logout();
    std::cout << "Logout successful!" << std::endl;
}
