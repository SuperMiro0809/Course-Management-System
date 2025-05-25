#pragma once

#include "Command.h"
#include "../utils/String.h"

class ChangePasswordCommand: public Command {
    String oldPassword;
    String newPassword;

    public:
        ChangePasswordCommand(const String& oldPassword, const String& newPassword);

        void execute(System& system) override;
};