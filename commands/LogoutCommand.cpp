#include "LogoutCommand.h"

#include <stdexcept>

void LogoutCommand::execute(System& system) {
    const User* currUser = system.getCurrentUser();

    if (!currUser) {
        throw std::logic_error("Command forbidden!");
    }

    system.logout();
    std::cout << "Logout successful!" << std::endl;
}
