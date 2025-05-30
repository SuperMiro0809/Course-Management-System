/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#pragma once

#include "../utils/String.h"

class CourseAssignment {
    unsigned int id;
    unsigned int courseId;
    String assignmentName;

    public:
        CourseAssignment(unsigned int id, unsigned int courseId, const String& assignmentName);

        unsigned int getCourseId() const;

        const String& getAssignmentName() const;
};