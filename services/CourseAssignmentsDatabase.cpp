#include "CourseAssignmentsDatabase.h"

#include <fstream>
#include <sstream>

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

unsigned int CourseAssignmentsDatabase::findCourseAssigment(unsigned int courseId, const String& homeworkName) const {
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
        String idStr, courseIdStr, homeworkStr;

        getline(ss, idStr, '|');
        getline(ss, courseIdStr, '|');
        getline(ss, homeworkStr);

        unsigned int currId = std::atoi(idStr.getElements());
        unsigned int currCourseId = std::atoi(courseIdStr.getElements());

        if (currCourseId == courseId && homeworkStr == homeworkName) {
            DBFile.close();
            return currId;
        }
    }

    return 0;
}