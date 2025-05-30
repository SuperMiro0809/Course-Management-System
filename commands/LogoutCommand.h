/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#pragma once

#include "Command.h"

class LogoutCommand: public Command {
    public:
        LogoutCommand() = default;

        void execute(System& system) override;
};