/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#pragma once

#include "../utils/String.h"

class Course {
    unsigned int id;
    String courseName;
    String coursePassword;
    unsigned int creatorId;

    public:
        Course(unsigned int id, const String& courseName, const String& coursePassword, unsigned int creatorId);

        unsigned int getId() const;

        const String& getPassword() const;

        unsigned int getCreatorId() const;

        const String& getCourseName() const;
};