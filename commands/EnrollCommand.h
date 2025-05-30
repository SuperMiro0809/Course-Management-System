/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#pragma once

#include "Command.h"
#include "../utils/String.h"

class EnrollCommand: public Command {
    String courseName;
    String coursePassword;

    public:
        EnrollCommand(const String& courseName, const String& coursePassword);

        void execute(System& system) override;
};