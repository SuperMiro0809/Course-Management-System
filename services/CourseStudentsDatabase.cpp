#include "CourseStudentsDatabase.h"

#include <fstream>
#include <sstream>
#include "MessagesDatabase.h"

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
            DBFile.close();
            return true;
        }
    }

    DBFile.close();
    return false;
}

void CourseStudentsDatabase::sendCourseMessage(unsigned int courseId, unsigned int sentById, const String& message) const {
    std::ifstream DBFile(dbName.getElements());

    if (!DBFile.is_open()) {
        throw std::runtime_error("Error: could not open database file");
    }

    MessagesDatabase messagesDb("../messages.txt");

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

        if (currCourseId == courseId) {
            messagesDb.sendMessage(sentById, currStudentId, message);
        }
    }

    DBFile.close();
    std::cout << "Message sent successfully!" << std::endl;
}