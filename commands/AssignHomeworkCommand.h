/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#pragma once

#include "Command.h"
#include "../utils/String.h"

class AssignHomeworkCommand: public Command {
    String courseName;
    String homeworkName;

    public:
        AssignHomeworkCommand(const String& courseName, const String& homeworkName);

        void execute(System& system) override;
};