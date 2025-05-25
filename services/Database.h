#pragma once

#include "../utils/String.h"

class Database {
    protected:
        String dbName;
    public:
        Database(const char* dbName);

        Database(const String& dbName);

        int autoIncrement() const;
};