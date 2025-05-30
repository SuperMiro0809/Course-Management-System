/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#pragma once

#include "Command.h"
#include "../utils/String.h"

class AddToCourseCommand: public Command {
    String courseName;
    unsigned int studentId;

    public:
        AddToCourseCommand(const String& courseName, unsigned int studentId);

        void execute(System& system) override;
};