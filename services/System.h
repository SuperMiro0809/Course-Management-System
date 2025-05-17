#pragma once

#include "../models/User.h"

class System {
    User* currentUser;

    public:
        System();

        const User* getCurrentUser() const;

        void setCurrentUser(User* user);

        void logout();
};