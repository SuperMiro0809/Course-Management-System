/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#pragma once

#include "Command.h"
#include "../utils/String.h"

class MessageCommand: public Command {
    unsigned int userId;
    String message;

    public:
        MessageCommand(unsigned int userId, const String& message);

        void execute(System& system) override;
};