/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#include "GradesDatabase.h"

#include <fstream>

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