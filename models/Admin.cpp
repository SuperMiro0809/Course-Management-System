#include "Admin.h"

Admin::Admin(const char* firstName, const char* familyName, unsigned int id): User(firstName, familyName, id) {
    userList.loadFromFile("../users.txt");
}

String Admin::getRole() const {
    return String("Admin");
}

User *Admin::clone() const {
    return new Admin(*this);
}
