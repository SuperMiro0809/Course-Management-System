#pragma once

#include "User.h"

class Student: public User {
public:
    Student();

    Student(const char* firstName, const char* familyName, unsigned int id);
};