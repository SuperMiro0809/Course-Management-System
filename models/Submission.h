/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#pragma once

#include "../utils/String.h"

class Submission {
    unsigned int id;
    unsigned int assignmentId;
    unsigned int studentId;
    String submission;

    public:
        Submission();

        Submission(unsigned int id, unsigned int assignmentId, unsigned int studentId, const String& submission);

        void addGrade(double grade, const String& message) const;

        unsigned int getStudentId() const;

        friend std::ostream& operator<<(std::ostream& os, const Submission& s);
};