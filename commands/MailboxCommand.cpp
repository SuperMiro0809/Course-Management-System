/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#include "MailboxCommand.h"

#include <stdexcept>
#include "../models/User.h"
#include "../models/Teacher.h"
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
    } else if (Teacher* teacher = dynamic_cast<Teacher*>(currUser)) {
        if (!teacher->getIsMailboxLoaded()) {
            teacher->loadMailbox();
        }
        const Mailbox& mailbox = teacher->getMailbox();
        std::cout << mailbox;
    } else {
        std::cout << "Current user has no mailbox.\n";
    }
}