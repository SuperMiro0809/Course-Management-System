#pragma once

#include "../models/User.h"

class UsersContainer {
    User** users;
    size_t size;
    size_t capacity;

    void freeDynamic();

    void copyDynamic(const UsersContainer& other);

    void resize(size_t newCapacity);

    public:
        UsersContainer();

        UsersContainer(const UsersContainer& other);

        UsersContainer& operator=(const UsersContainer& other);

        ~UsersContainer();

        void add(const User& user);

        void loadFromFile(const char* filename);

        const User* operator[](size_t index) const;

        size_t getUsersCount() const;
};