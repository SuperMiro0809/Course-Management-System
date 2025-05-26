#include "Student.h"

Student::Student(const char* firstName, const char* familyName, unsigned int id): User(firstName, familyName, id) {}

const String& Student::getRole() const {
    return String("Student");
}