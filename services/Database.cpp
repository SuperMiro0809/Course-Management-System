/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#include "Database.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

Database::Database(const char* dbName): dbName(std::strlen(dbName), dbName) {}

Database::Database(const String& dbName): dbName(dbName) {}

int Database::autoIncrement() const {
    std::ifstream DBFile(dbName.getElements());

    if (!DBFile.is_open()) {
        throw std::runtime_error("Error: could not open database file");
    }

    String line;
    unsigned int currentId = 0;

    while (true) {
        getline(DBFile, line);

        if (DBFile.eof()) {
            break;
        }

        std::stringstream ss(line.getElements());
        String idStr;
        getline(ss, idStr, '|');

        unsigned int currId = std::atoi(idStr.getElements());

        if (currId > 0) {
            currentId = currId;
        }
    }

    DBFile.close();

    return currentId + 1;
}
