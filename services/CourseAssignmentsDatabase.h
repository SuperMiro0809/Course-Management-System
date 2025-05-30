/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#pragma once

#include "Database.h"
#include "../utils/String.h"
#include "../models/CourseAssignment.h"

class CourseAssignmentsDatabase: public Database {
    public:
        explicit CourseAssignmentsDatabase(const char* dbName);

        void addNewAssignment(unsigned int courseId, const String& homework) const;

        unsigned int findCourseAssigment(unsigned int courseId, const String& homeworkName) const;

        const CourseAssignment* findCourseAssigment(unsigned int id) const;
};