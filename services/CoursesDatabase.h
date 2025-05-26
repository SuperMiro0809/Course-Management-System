#pragma once

#include "Database.h"

class CoursesDatabase: public Database {
    public:
        CoursesDatabase(const char* dbName);

        void addNewCourse(const String& courseName, const String& coursePassword, unsigned int createdBy) const;

        unsigned int findCreatorCourse(const String& courseName, unsigned int createdBy) const;
};