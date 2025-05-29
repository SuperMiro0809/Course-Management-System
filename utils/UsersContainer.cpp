#include "UsersContainer.h"

#include <fstream>
#include <sstream>
#include "String.h"
#include "../models/Teacher.h"
#include "../models/Student.h"

void UsersContainer::freeDynamic() {
    for (size_t i = 0; i < size; i++) {
        delete users[i];
    }

    delete[] users;
}

void UsersContainer::copyDynamic(const UsersContainer& other) {
    users = new User*[other.capacity];
    for (size_t i = 0; i < other.size; i++) {
        users[i] = other.users[i]->clone();
    }
}

void UsersContainer::resize(size_t newCapacity) {
    capacity = newCapacity;
    User** temp = new User*[capacity];

    for (size_t i = 0; i < size; i++) {
        temp[i] = users[i];
    }

    delete[] users;
    users = temp;
}

UsersContainer::UsersContainer() {
    size = 0;
    capacity = 8;
    users = new User*[capacity];
}

UsersContainer::UsersContainer(const UsersContainer& other) {
    size = other.size;
    capacity = other.capacity;
    copyDynamic(other);
}

UsersContainer& UsersContainer::operator=(const UsersContainer& other) {
    if (this != &other) {
        freeDynamic();
        size = other.size;
        capacity = other.capacity;
        copyDynamic(other);
    }

    return *this;
}

UsersContainer::~UsersContainer() {
    freeDynamic();
}

void UsersContainer::add(const User& user) {
    if (size == capacity) {
        resize(capacity * 2);
    }

    users[size++] = user.clone();
}

void UsersContainer::loadFromFile(const char* filename) {
    std::ifstream DBFile(filename);
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
        String idStr, firstNameStr, lastNameStr, roleStr;

        getline(ss, idStr, '|');
        getline(ss, firstNameStr, '|');
        getline(ss, lastNameStr, '|');
        getline(ss, roleStr, '|');

        unsigned int currId = std::atoi(idStr.getElements());

        if (roleStr == "Teacher") {
          add(Teacher(firstNameStr.getElements(), lastNameStr.getElements(), currId));
        } else if (roleStr == "Student") {
          add(Student(firstNameStr.getElements(), lastNameStr.getElements(), currId));
        }
    }

    DBFile.close();
}