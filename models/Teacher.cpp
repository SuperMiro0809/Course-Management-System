#include "Teacher.h"

Teacher::Teacher(const char* firstName, const char* familyName, unsigned int id): User(firstName, familyName, id) {}

String Teacher::getRole() const {
    return String("Teacher");
}

User *Teacher::clone() const {
    return new Teacher(*this);
}
