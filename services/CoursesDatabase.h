#pragma once

#include "Database.h"

class CoursesDatabase: public Database {
    public:
        CoursesDatabase(const char* dbName);

        void addNewCourse(const String& courseName, const String& coursePassword, unsigned int createdBy);
};