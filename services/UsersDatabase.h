#pragma once

#include "Database.h"
#include "../utils/String.h"

class UsersDatabase: public Database {
    public:
        UsersDatabase(const char* dbName);

        void addNewUser(const String& firstName, const String& familyName, const char* role, const String& password);
};