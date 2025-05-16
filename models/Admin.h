#pragma once

#include "User.h"

class Admin: public User {
public:
    Admin();

    Admin(const char* firstName, const char* familyName, unsigned int id);
};