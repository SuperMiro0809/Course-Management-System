/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#pragma once

#include "Command.h"
#include "../utils/String.h"

class GradeAssignmentCommand: public Command {
    String courseName;
    String assignmentName;
    unsigned int studentId;
    double grade;
    String message;

    public:
        GradeAssignmentCommand(
            const String& courseName,
            const String& assignmentName,
            unsigned int studentId,
            double grade,
            const String& message
        );

        void execute(System& system) override;
};