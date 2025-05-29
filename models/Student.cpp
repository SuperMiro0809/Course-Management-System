#include "Student.h"

Student::Student(const char* firstName, const char* familyName, unsigned int id): User(firstName, familyName, id) {
    mailbox.loadFromFile("../messages.txt", id);
}

String Student::getRole() const {
    return String("Student");
}

const Mailbox& Student::getMailbox() const {
    return mailbox;
}

void Student::clearMailbox() {
    mailbox.clearMailbox("../messages.txt", id);
}
