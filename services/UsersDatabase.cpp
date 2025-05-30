/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#include "UsersDatabase.h"

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include "../models/Admin.h"
#include "../models/Teacher.h"
#include "../models/Student.h"

UsersDatabase::UsersDatabase(const char* dbName): Database(dbName) {}

unsigned int UsersDatabase::addNewUser(const String& firstName, const String& familyName, const char* role, const String& password) const {
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

    DBFile.close();

    return nextId;
}

void UsersDatabase::changePassword(unsigned int id, const String& oldPassword, const String& newPassword) const {
    std::ifstream DBFile(dbName.getElements());
    if (!DBFile.is_open()) {
        throw std::runtime_error("Error: could not open database file");
    }

    std::ofstream TempFile("../users_temp.txt");
    if (!TempFile.is_open()) {
        throw std::runtime_error("Failed to open temporary file for writing");
    }

    String line;
    while (true) {
        getline(DBFile, line);

        if (DBFile.eof()) {
            break;
        }

        std::stringstream ss(line.getElements());
        String idStr, firstNameStr, lastNameStr, roleStr, passStr;

        getline(ss, idStr, '|');
        getline(ss, firstNameStr, '|');
        getline(ss, lastNameStr, '|');
        getline(ss, roleStr, '|');
        getline(ss, passStr, '|');

        unsigned int currId = std::atoi(idStr.getElements());

        if (currId == id) {
            if (passStr != oldPassword) {
                DBFile.close();
                TempFile.close();
                std::remove("../users_temp.txt");
                throw std::runtime_error("Incorrect old password.");
            }

            passStr = newPassword;
        }

        if (!idStr.empty() && !firstNameStr.empty() && !lastNameStr.empty() && !roleStr.empty() && !passStr.empty()) {
            TempFile << idStr << '|' << firstNameStr << '|' << lastNameStr << '|'
                     << roleStr << '|' << passStr << '\n';
        }

    }

    DBFile.close();
    TempFile.close();

    std::remove(dbName.getElements());
    std::rename("../users_temp.txt", dbName.getElements());

    std::cout << "Password changed successfully!" << std::endl;
}

const User* UsersDatabase::getUserById(unsigned int id) const {
    std::ifstream DBFile(dbName.getElements());
    if (!DBFile.is_open()) {
        throw std::runtime_error("Error: could not open database file");
    }

    String line;
    while (true) {
        getline(DBFile, line);

        if (DBFile.eof()) {
            break;
        }

        std::stringstream ss(line.getElements());
        String idStr, firstNameStr, lastNameStr, roleStr, passStr;

        getline(ss, idStr, '|');
        getline(ss, firstNameStr, '|');
        getline(ss, lastNameStr, '|');
        getline(ss, roleStr, '|');
        getline(ss, passStr, '|');

        unsigned int currId = std::atoi(idStr.getElements());

        if (currId == id) {
            if (roleStr == "Admin") {
                return new Admin(firstNameStr.getElements(), lastNameStr.getElements(), currId);
            } else if (roleStr == "Teacher") {
                return new Teacher(firstNameStr.getElements(), lastNameStr.getElements(), currId);
            } else if (roleStr == "Student") {
                return new Student(firstNameStr.getElements(), lastNameStr.getElements(), currId);
            }
        }
    }

    return nullptr;
}