/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#include "GradesCommand.h"

#include "../models/Student.h"

void GradesCommand::execute(System& system) {
    User* currUser = system.getCurrentUser();

    if (!currUser) {
        throw std::logic_error("Command forbidden!");
    }

    if (Student* student = dynamic_cast<Student*>(currUser)) {
        if (!student->getAreGradesLoaded()) {
            student->loadGrades();
        }
        const GradesContainer& grades = student->getGrades();
        std::cout << grades;
    } else {
        std::cout << "Current user has no grades.\n";
    }
}