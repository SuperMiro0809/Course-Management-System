#pragma once

#include "Database.h"
#include "../utils/String.h"

class CourseAssignmentsDatabase: public Database {
    public:
        explicit CourseAssignmentsDatabase(const char* dbName);

        void addNewAssignment(unsigned int courseId, const String& homework) const;

        unsigned int findCourseAssigment(unsigned int courseId, const String& homeworkName) const;
};