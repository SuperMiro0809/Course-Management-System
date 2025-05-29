#include "Admin.h"

#include "Student.h"
#include "Teacher.h"
#include "../services/MessagesDatabase.h"
#include "../services/UsersDatabase.h"

Admin::Admin(const char* firstName, const char* familyName, unsigned int id): User(firstName, familyName, id) {}

String Admin::getRole() const {
    return String("Admin");
}

User *Admin::clone() const {
    return new Admin(*this);
}

void Admin::loadUserList() {
    userList.loadFromFile("../users.txt");
    areUsersLoaded = true;
}

void Admin::messageAllUsers(const String& messageText) {
    if (!areUsersLoaded) {
        loadUserList();
    }

    MessagesDatabase messagesDb("../messages.txt");

    for (size_t i = 0; i < userList.getUsersCount(); i++) {
        const User* user = userList[i];

        if (user->getId() != this->getId()) {
            messagesDb.sendMessage(this->getId(), user->getId(), messageText);
        }
    }
}

void Admin::addNewProfile(const String& firstName, const String& familyName, const String& password, const char* role) {
    UsersDatabase usersDb("../users.txt");

    if (!areUsersLoaded) {
        loadUserList();
    }

    unsigned int id = usersDb.addNewUser(firstName, familyName, role, password);

    if (std::strcmp(role, "Teacher") == 0) {
        userList.add(Teacher(firstName.getElements(), familyName.getElements(), id));
    } else if (std::strcmp(role, "Student") == 0) {
        userList.add(Student(firstName.getElements(), familyName.getElements(), id));
    }
}
