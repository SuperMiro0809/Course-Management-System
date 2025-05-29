#pragma once

#include "Database.h"
#include "../utils/String.h"
#include "../models/User.h"

class UsersDatabase: public Database {
    public:
        explicit UsersDatabase(const char* dbName);

        unsigned int addNewUser(const String& firstName, const String& familyName, const char* role, const String& password) const;

        void changePassword(unsigned int id, const String& oldPassword, const String& newPassword) const;

        const User* getUserById(unsigned int id) const;
};