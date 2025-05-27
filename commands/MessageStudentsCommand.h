#pragma once

#include "Command.h"
#include "../utils/String.h"

class MessageStudentsCommand: public Command {
    String courseName;
    String message;

    public:
        MessageStudentsCommand(const String& courseName, const String& message);

        void execute(System& system) override;
};