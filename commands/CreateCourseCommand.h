/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#pragma once

#include "Command.h"
#include "../utils/String.h"

class CreateCourseCommand: public Command {
    String courseName;
    String coursePassword;
    String password;

    public:
        CreateCourseCommand(const String& courseName, const String& coursePassword);

        void execute(System& system) override;
};