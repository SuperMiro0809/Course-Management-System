#include <iostream>
#include <stdexcept>

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
            try {
                cmd->execute(system);
            } catch (const std::logic_error& e) {
                std::cout << e.what() << std::endl;
            } catch (const std::runtime_error& e) {
                std::cout << e.what() << std::endl;
            }

            delete cmd;
        } else {
            std::cout << "Invalid command! Please try again" << std::endl;
        }
    }

    return 0;
}