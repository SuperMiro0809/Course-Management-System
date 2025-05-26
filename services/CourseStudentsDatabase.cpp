#include "CourseStudentsDatabase.h"

#include <fstream>

CourseStudentsDatabase::CourseStudentsDatabase(const char* dbName): Database(dbName) {}

void CourseStudentsDatabase::addNewCourseStudent(unsigned int courseId, unsigned int studentId) const {
    int nextId = autoIncrement();

    std::ofstream DBFile(dbName.getElements(), std::ios::app);

    if (!DBFile.is_open()) {
        throw std::runtime_error("Error: could not open database file");
    }

    DBFile << nextId << '|';
    DBFile << courseId << '|';
    DBFile << studentId << '\n';

    std::cout << "Student with ID " << studentId << " added to course with ID " << courseId
              << " successfully!" << std::endl;

    DBFile.close();
}