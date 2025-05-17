#include "LoginCommand.h"

#include <fstream>
#include <sstream>
#include "../models/Admin.h"
#include "../models/Teacher.h"
#include "../models/Student.h"

LoginCommand::LoginCommand(unsigned int id, const String& password): Command() {
    this->id = id;
    this->password = password;
}

void LoginCommand::execute(System& system) {
    std::ifstream UsersFile("../users.txt");

    if (!UsersFile.is_open()) {
        std::cout << "Error: could not open users.txt" << std::endl;
        return;
    }

    String line;
    while (true) {
        if (UsersFile.eof()) {
            break;
        }

        getline(UsersFile, line);
        std::stringstream ss(line.getElements());
        String idStr, firstNameStr, lastNameStr, roleStr, passStr;

        getline(ss, idStr, '|');
        getline(ss, firstNameStr, '|');
        getline(ss, lastNameStr, '|');
        getline(ss, roleStr, '|');
        getline(ss, passStr, '|');

        unsigned int currId = std::atoi(idStr.getElements());

        if (currId == id && passStr == password) {
            if (roleStr == "Admin") {
                Admin* adminPtr = new Admin(firstNameStr.getElements(), lastNameStr.getElements(), currId);
                system.setCurrentUser(adminPtr);
            } else if (roleStr == "Teacher") {
                Teacher* teacherPtr = new Teacher(firstNameStr.getElements(), lastNameStr.getElements(), currId);
                system.setCurrentUser(teacherPtr);
            } else if (roleStr == "Student") {
                Student* studentPtr = new Student(firstNameStr.getElements(), lastNameStr.getElements(), currId);
                system.setCurrentUser(studentPtr);
            }

            std::cout << "Login successful!" << std::endl;
            std::cout <<  firstNameStr << " " << lastNameStr << " | " << roleStr << " | " << currId << std::endl;
            return;
        }
    }
}
