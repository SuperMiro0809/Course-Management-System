#include "CoursesDatabase.h"

#include <fstream>

CoursesDatabase::CoursesDatabase(const char* dbName): Database(dbName) {}

void CoursesDatabase::addNewCourse(const String& courseName, const String& coursePassword) {
    int nextId = autoIncrement();

    std::ofstream DBFile(dbName.getElements(), std::ios::app);

    if (!DBFile.is_open()) {
        throw std::runtime_error("Error: could not open database file");
    }

    DBFile << nextId << '|';
    DBFile << courseName.getElements() << '|';
    DBFile << coursePassword.getElements() << '\n';

    std::cout << "Added course " << courseName.getElements()
              << " successfully!" << std::endl;
}
