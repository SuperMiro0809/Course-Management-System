#include "AssigmentSubmissionsDatabase.h"

#include <fstream>
#include <sstream>

AssigmentSubmissionsDatabase::AssigmentSubmissionsDatabase(const char* dbName): Database(dbName) {}

void AssigmentSubmissionsDatabase::addNewSubmission(unsigned int assignmentId, unsigned int userId, const String& submission) const {
    int nextId = autoIncrement();

    std::ofstream DBFile(dbName.getElements(), std::ios::app);

    if (!DBFile.is_open()) {
        throw std::runtime_error("Error: could not open database file");
    }

    DBFile << nextId << '|';
    DBFile << assignmentId << '|';
    DBFile << userId << '|';
    DBFile << submission << '\n';

    std::cout << "Assigment submitted successfully!" << std::endl;

    DBFile.close();
}

bool AssigmentSubmissionsDatabase::isAlreadySubmitted(unsigned int assignmentId, unsigned int userId) const {
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
        String idStr, assignmentIdStr, userIdStr;

        getline(ss, idStr, '|');
        getline(ss, assignmentIdStr, '|');
        getline(ss, userIdStr, '|');

        unsigned int currAssignmentId = std::atoi(assignmentIdStr.getElements());
        unsigned int currUserId = std::atoi(userIdStr.getElements());

        if (currAssignmentId == assignmentId && currUserId == userId) {
            DBFile.close();
            return true;
        }
    }

    DBFile.close();
    return false;
}