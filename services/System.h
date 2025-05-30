/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#pragma once

#include "../models/User.h"

class System {
    User* currentUser;

    public:
        System();

        const User* getCurrentUser() const;

        User* getCurrentUser();

        void setCurrentUser(User* user);

        void logout();
};