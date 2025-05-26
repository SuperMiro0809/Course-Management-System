#pragma once

#include "User.h"
#include "../utils/String.h"

class Admin: public User {
public:
    Admin(const char* firstName, const char* familyName, unsigned int id);

    String getRole() const override;
};