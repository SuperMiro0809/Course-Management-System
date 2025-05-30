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

        friend std::ostream& operator<<(std::ostream& os, const Submission& s);
};