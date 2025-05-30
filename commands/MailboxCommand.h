/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#pragma once

#include "Command.h"

class MailboxCommand: public Command {
    public:
        MailboxCommand() = default;

        void execute(System& system) override;
};