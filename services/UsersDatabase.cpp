#include "UsersDatabase.h"

#include <iostream>
#include <fstream>
#include <stdexcept>

UsersDatabase::UsersDatabase(const char* dbName): Database(dbName) {}

void UsersDatabase::addNewUser(const String& firstName, const String& familyName, const char* role, const String& password) {
    int nextId = autoIncrement();

    std::ofstream DBFile(dbName.getElements(), std::ios::app);

    if (!DBFile.is_open()) {
        throw std::runtime_error("Error: could not open database file");
    }

    DBFile << nextId << '|';
    DBFile << firstName.getElements() << '|';
    DBFile << familyName.getElements() << '|';
    DBFile << role << '|';
    DBFile << password.getElements() << '\n';

    std::cout << "Added " << role << " "
              << firstName.getElements() << " "
              << familyName.getElements()
              << " with ID " << nextId << "!"
              << std::endl;
}