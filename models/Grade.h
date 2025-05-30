/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#pragma once

#include "../utils/String.h"

class Grade {
    unsigned int id;
    unsigned int assignmentId;
    unsigned int studentId;
    double grade;
    String message;

    public:
        Grade();

        Grade(
            unsigned int id,
            unsigned int assignmentId,
            unsigned int studentId,
            double grade,
            String message
        );

        friend std::ostream& operator<<(std::ostream& os, const Grade& grade);
};