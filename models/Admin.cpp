#include "Admin.h"

#include "../services/MessagesDatabase.h"

Admin::Admin(const char* firstName, const char* familyName, unsigned int id): User(firstName, familyName, id) {}

String Admin::getRole() const {
    return String("Admin");
}

User *Admin::clone() const {
    return new Admin(*this);
}

void Admin::messageAllUsers(const String& messageText) {
    if (!areUsersLoaded) {
        userList.loadFromFile("../users.txt");
        areUsersLoaded = true;
    }

    MessagesDatabase messagesDb("../messages.txt");

    for (size_t i = 0; i < userList.getUsersCount(); i++) {
        const User* user = userList[i];

        if (user->getId() != this->getId()) {
            messagesDb.sendMessage(this->getId(), user->getId(), messageText);
        }
    }
}
