#include "Teacher.h"

Teacher::Teacher(const char* firstName, const char* familyName, unsigned int id): User(firstName, familyName, id) {}

Teacher::Teacher(const String& firstName, const String& familyName, unsigned int id): User(firstName, familyName, id) {}

String Teacher::getRole() const {
    return String("Teacher");
}

const Mailbox& Teacher::getMailbox() const {
    return mailbox;
}

bool Teacher::getIsMailboxLoaded() const {
    return isMailboxLoaded;
}

void Teacher::loadMailbox() {
    mailbox.loadFromFile("../messages.txt", id);
    isMailboxLoaded = true;
}

void Teacher::clearMailbox() {
    mailbox.clearMailbox("../messages.txt", id);
}

User *Teacher::clone() const {
    return new Teacher(*this);
}
