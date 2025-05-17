#include <iostream>

#include "services/System.h"
#include "utils/String.h"
#include "commands/CommandFactory.h"
#include "commands/Command.h"

int main() {
    using ::getline;
    System system;

    String input;
    CommandFactory commandFactory;

    std::cout << "Welcome to the Course Management System" << std::endl;

    while (true) {
        getline(std::cin, input);

        if (input.empty()) continue;
        if (input == "exit") break;

        if (Command* cmd = commandFactory.create(input)) {
            cmd->execute(system);
            delete cmd;
        } else {
            std::cout << "Invalid command! Please try again" << std::endl;
        }
    }

    return 0;
}