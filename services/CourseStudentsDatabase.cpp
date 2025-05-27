#include "CourseStudentsDatabase.h"

#include <fstream>
#include <sstream>

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

bool CourseStudentsDatabase::isStudentAddedToCourse(unsigned int courseId, unsigned int studentId) const {
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
        String idStr, courseIdStr, studentIdStr;

        getline(ss, idStr, '|');
        getline(ss, courseIdStr, '|');
        getline(ss, studentIdStr);

        unsigned int currCourseId = std::atoi(courseIdStr.getElements());
        unsigned int currStudentId = std::atoi(studentIdStr.getElements());

        if (currCourseId == courseId && currStudentId == studentId) {
            return true;
        }
    }

    return false;
}