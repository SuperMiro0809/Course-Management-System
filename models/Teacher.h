#pragma once

#include "User.h"

class Teacher: public User {
public:
    Teacher(const char* firstName, const char* familyName, unsigned int id);
};