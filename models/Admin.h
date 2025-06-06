/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#pragma once

#include "User.h"
#include "../utils/String.h"
#include "../utils/UsersContainer.h"

class Admin: public User {
    UsersContainer userList;
    bool areUsersLoaded = false;

public:
    Admin(const char* firstName, const char* familyName, unsigned int id);

    String getRole() const override;

    User* clone() const override;

    void loadUserList();

    void messageAllUsers(const String& messageText);

    void addNewProfile(const String& firstName, const String& familyName, const String& password, const char* role);
};