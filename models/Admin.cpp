#include "Admin.h"

Admin::Admin(const char* firstName, const char* familyName, unsigned int id): User(firstName, familyName, id) {}

const String& Admin::getRole() const {
    return String("Admin");
}