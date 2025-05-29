#include "MailboxCommand.h"

#include <stdexcept>
#include "../models/User.h"
#include "../models/Student.h"
#include "../utils/Mailbox.h"

void MailboxCommand::execute(System& system) {
    User* currUser = system.getCurrentUser();

    if (!currUser) {
        throw std::logic_error("Command forbidden!");
    }

    if (Student* student = dynamic_cast<Student*>(currUser)) {
        if (!student->getIsMailboxLoaded()) {
            student->loadMailbox();
        }
        const Mailbox& mailbox = student->getMailbox();
        std::cout << mailbox;
    } else {
        std::cout << "Current user has no mailbox.\n";
    }
}