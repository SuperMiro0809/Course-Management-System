/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#include "AddStudentCommand.h"

#include <stdexcept>

#include "../models/Admin.h"
#include "../models/User.h"

AddStudentCommand::AddStudentCommand(const String& firstName, const String& familyName, const String& password)
  : Command(),
    firstName(firstName),
    familyName(familyName),
    password(password) {}

void AddStudentCommand::execute(System& system) {
    User* currUser = system.getCurrentUser();

    if (!currUser) {
        throw std::logic_error("Command forbidden!");
    }

    if (Admin* admin = dynamic_cast<Admin*>(currUser)) {
       admin->addNewProfile(firstName, familyName, password, "Student");
    } else {
        std::cout << "Command forbidden!\n";
    }
}