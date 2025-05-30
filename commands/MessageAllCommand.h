/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#pragma once

#include "Command.h"
#include "../utils/String.h"

class MessageAllCommand: public Command {
    String message;

    public:
        MessageAllCommand(const String& message);

        void execute(System& system) override;
};