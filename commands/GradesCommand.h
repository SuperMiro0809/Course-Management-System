/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#pragma once

#include "Command.h"

class GradesCommand: public Command {
    public:
        GradesCommand() = default;

        void execute(System& system) override;
};