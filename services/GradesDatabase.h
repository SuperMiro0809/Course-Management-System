#pragma once

#include "Database.h"

class GradesDatabase: public Database {
    public:
        explicit GradesDatabase(const char* dbName);

        void addGrade(unsigned int assignmentId, unsigned int studentId, double grade, const String& message) const;
};