#pragma once

#include "Database.h"

class CourseStudentsDatabase: public Database {
    public:
        CourseStudentsDatabase(const char* dbName);

        void addNewCourseStudent(unsigned int courseId, unsigned int studentId) const;

        bool isStudentAddedToCourse(unsigned int courseId, unsigned int studentId) const;
};