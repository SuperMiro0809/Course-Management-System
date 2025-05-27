#include "CourseAssignmentsDatabase.h"

#include <fstream>

CourseAssignmentsDatabase::CourseAssignmentsDatabase(const char* dbName): Database(dbName) {}

void CourseAssignmentsDatabase::addNewAssignment(unsigned int courseId, const String& homework) const {
    int nextId = autoIncrement();

    std::ofstream DBFile(dbName.getElements(), std::ios::app);

    if (!DBFile.is_open()) {
        throw std::runtime_error("Error: could not open database file");
    }

    DBFile << nextId << '|';
    DBFile << courseId << '|';
    DBFile << homework << '\n';

    std::cout << "Successfully created a new assignment!" << std::endl;

    DBFile.close();
}