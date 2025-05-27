#include "MailboxCommand.h"

#include <stdexcept>
#include "../models/User.h"
#include "../models/Student.h"
#include "../utils/Mailbox.h"

void MailboxCommand::execute(System& system) {
    const User* currUser = system.getCurrentUser();

    if (!currUser) {
        throw std::logic_error("Command forbidden!");
    }

    if (const Student* student = dynamic_cast<const Student*>(currUser)) {
        const Mailbox& mailbox = student->getMailbox();
        std::cout << mailbox;
    } else {
        std::cout << "Current user has no mailbox.\n";
    }
}