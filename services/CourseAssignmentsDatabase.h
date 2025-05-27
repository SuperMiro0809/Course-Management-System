#pragma once

#include "Database.h"
#include "../utils/String.h"

class CourseAssignmentsDatabase: public Database {
    public:
        CourseAssignmentsDatabase(const char* dbName);

        void addNewAssignment(unsigned int courseId, const String& homework) const;
};