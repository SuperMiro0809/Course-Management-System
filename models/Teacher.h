#pragma once

#include "User.h"
#include "../utils/String.h"

class Teacher: public User {
public:
    Teacher(const char* firstName, const char* familyName, unsigned int id);

    String getRole() const override;

    User* clone() const override;
};