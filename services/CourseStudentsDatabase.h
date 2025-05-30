/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#pragma once

#include "Database.h"
#include "../utils/String.h"

class CourseStudentsDatabase: public Database {
    public:
        explicit CourseStudentsDatabase(const char* dbName);

        void addNewCourseStudent(unsigned int courseId, unsigned int studentId) const;

        bool isStudentAddedToCourse(unsigned int courseId, unsigned int studentId) const;

        void sendCourseMessage(unsigned int courseId, unsigned int sentById, const String& message) const;
};