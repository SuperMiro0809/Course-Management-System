#pragma once

#include "../utils/String.h"

class Database {
    protected:
        String dbName;
    public:
        explicit Database(const char* dbName);

        explicit Database(const String& dbName);

        int autoIncrement() const;
};