/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#pragma once

#include "Database.h"
#include "../models/Course.h"

class CoursesDatabase: public Database {
    public:
        explicit CoursesDatabase(const char* dbName);

        void addNewCourse(const String& courseName, const String& coursePassword, unsigned int createdBy) const;

        unsigned int findCreatorCourse(const String& courseName, unsigned int createdBy) const;

        const Course* findCourseByName(const String& courseName) const;

        const Course* findCourseById(unsigned int id) const;
};