#pragma once

#include "Command.h"
#include "../utils/String.h"

class LoginCommand: public Command {
    unsigned int id;
    String password;

    public:
        LoginCommand(unsigned int id, const String& password);

        void execute(System& system) override;
};