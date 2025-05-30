#pragma once

#include "Command.h"

class GradesCommand: public Command {
    public:
        GradesCommand() = default;

        void execute(System& system) override;
};