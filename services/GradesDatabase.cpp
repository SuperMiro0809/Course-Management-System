/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#include "GradesDatabase.h"

#include <fstream>
#include <sstream>

GradesDatabase::GradesDatabase(const char* dbName): Database(dbName) {}

void GradesDatabase::addGrade(unsigned int assignmentId, unsigned int studentId, double grade, const String& message) const {
    int nextId = autoIncrement();

    std::ofstream DBFile(dbName.getElements(), std::ios::app);

    if (!DBFile.is_open()) {
        throw std::runtime_error("Error: could not open database file");
    }

    std::time_t now = std::time(nullptr);

    DBFile << nextId << '|';
    DBFile << assignmentId << '|';
    DBFile << studentId << '|';
    DBFile << grade << '|';
    DBFile << message << '\n';

    DBFile.close();
}

bool GradesDatabase::isAlreadyGraded(unsigned int assignmentId, unsigned int studentId) const {
    std::ifstream DBFile(dbName.getElements());

    if (!DBFile.is_open()) {
        throw std::runtime_error("Error: could not open database file");
    }

    String line;
    while (true) {
        getline(DBFile, line);

        if (DBFile.eof()) {
            break;
        }

        std::stringstream ss(line.getElements());
        String idStr, assignmentIdStr, studentIdStr;

        getline(ss, idStr, '|');
        getline(ss, assignmentIdStr, '|');
        getline(ss, studentIdStr, '|');

        unsigned int currId = std::atoi(idStr.getElements());
        unsigned int currAssignmentId = std::atoi(assignmentIdStr.getElements());
        unsigned int currStudentId = std::atoi(studentIdStr.getElements());

        if (currAssignmentId == assignmentId && currStudentId == studentId) {
            DBFile.close();
            return true;
        }
    }

    DBFile.close();
    return false;
}