#pragma once

#include "Command.h"
#include "../utils/String.h"

class SubmitAssignmentCommand: public Command {
    String courseName;
    String assignmentName;
    String submission;

    public:
        SubmitAssignmentCommand(const String& courseName, const String& assignmentName, const String& submission);

        void execute(System& system) override;
};