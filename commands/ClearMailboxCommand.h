#pragma once

#include "Command.h"

class ClearMailboxCommand: public Command {
    public:
        ClearMailboxCommand() = default;

        void execute(System& system) override;
};