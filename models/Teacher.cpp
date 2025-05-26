#include "Teacher.h"

Teacher::Teacher(const char* firstName, const char* familyName, unsigned int id): User(firstName, familyName, id) {}

const String& Teacher::getRole() const {
    return String("Teacher");
}