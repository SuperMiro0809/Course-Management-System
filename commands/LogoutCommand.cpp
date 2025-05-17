#include "LogoutCommand.h"

void LogoutCommand::execute(System& system) {
    system.logout();
    std::cout << "Logout successful!" << std::endl;
}
