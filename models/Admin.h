#pragma once

#include "User.h"
#include "../utils/String.h"
#include "../utils/UsersContainer.h"

class Admin: public User {
    UsersContainer userList;
public:
    Admin(const char* firstName, const char* familyName, unsigned int id);

    String getRole() const override;

    User* clone() const override;
};