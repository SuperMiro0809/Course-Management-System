#include "Student.h"

Student::Student(const char* firstName, const char* familyName, unsigned int id): User(firstName, familyName, id) {}

Student::Student(const String& firstName, const String& familyName, unsigned int id): User(firstName, familyName, id) {}

String Student::getRole() const {
    return String("Student");
}

const Mailbox& Student::getMailbox() const {
    return mailbox;
}

bool Student::getIsMailboxLoaded() const {
    return isMailboxLoaded;
}

void Student::loadMailbox() {
    mailbox.loadFromFile("../messages.txt", id);
    isMailboxLoaded = true;
}

void Student::clearMailbox() {
    mailbox.clearMailbox("../messages.txt", id);
}

const GradesContainer& Student::getGrades() const {
    return grades;
}

bool Student::getAreGradesLoaded() const {
    return areGradesLoaded;
}

void Student::loadGrades() {
    grades.loadFromFile("../grades.txt", id);
    areGradesLoaded = true;
}

User *Student::clone() const {
    return new Student(*this);
}

