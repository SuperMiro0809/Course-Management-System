#include "ClearMailboxCommand.h"

#include "../models/Student.h"

void ClearMailboxCommand::execute(System& system) {
    User* currUser = system.getCurrentUser();

    if (!currUser) {
        throw std::logic_error("Command forbidden!");
    }

    if (Student* student = dynamic_cast<Student*>(currUser)) {
        student->clearMailbox();
    } else {
        std::cout << "Current user has no mailbox.\n";
    }
}