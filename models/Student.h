#pragma once

#include "User.h"
#include "../utils/String.h"

class Student: public User {
public:
    Student(const char* firstName, const char* familyName, unsigned int id);

    const String& getRole() const override;
};