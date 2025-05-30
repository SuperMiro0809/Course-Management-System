/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#pragma once

#include "Command.h"
#include "../utils/String.h"

class ViewAssignmentSubmissions: public Command {
    String courseName;
    String assignmentName;

    public:
        ViewAssignmentSubmissions(const String& courseName, const String& assignmentName);

        void execute(System& system) override;
};