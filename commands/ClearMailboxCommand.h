/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#pragma once

#include "Command.h"

class ClearMailboxCommand: public Command {
    public:
        ClearMailboxCommand() = default;

        void execute(System& system) override;
};