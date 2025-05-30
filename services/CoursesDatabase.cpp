#include "CoursesDatabase.h"

#include <fstream>
#include <sstream>

CoursesDatabase::CoursesDatabase(const char* dbName): Database(dbName) {}

void CoursesDatabase::addNewCourse(const String& courseName, const String& coursePassword, unsigned int createdBy) const {
    int nextId = autoIncrement();

    std::ofstream DBFile(dbName.getElements(), std::ios::app);

    if (!DBFile.is_open()) {
        throw std::runtime_error("Error: could not open database file");
    }

    DBFile << nextId << '|';
    DBFile << courseName.getElements() << '|';
    DBFile << coursePassword.getElements() << '|';
    DBFile << createdBy << '\n';

    std::cout << "Added course " << courseName.getElements()
              << " successfully!" << std::endl;

    DBFile.close();
}

unsigned int CoursesDatabase::findCreatorCourse(const String& courseName, unsigned int createdBy) const {
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
        String idStr, courseNameStr, coursePasswordStr, createdByStr;

        getline(ss, idStr, '|');
        getline(ss, courseNameStr, '|');
        getline(ss, coursePasswordStr, '|');
        getline(ss, createdByStr, '|');

        unsigned int currCreatedById = std::atoi(createdByStr.getElements());

        if (courseName == courseNameStr && createdBy == currCreatedById) {
            DBFile.close();
            return std::atoi(idStr.getElements());
        }
    }

    DBFile.close();
    return 0;
}

const Course* CoursesDatabase::findCourseByName(const String& courseName) const {
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
        String idStr, courseNameStr, coursePasswordStr, createdByStr;

        getline(ss, idStr, '|');
        getline(ss, courseNameStr, '|');
        getline(ss, coursePasswordStr, '|');
        getline(ss, createdByStr);

        unsigned int currId = std::atoi(idStr.getElements());
        unsigned int currCreatedById = std::atoi(createdByStr.getElements());

        if (courseName == courseNameStr) {
            DBFile.close();
            return new Course(currId, courseNameStr, coursePasswordStr, currCreatedById);
        }
    }

    DBFile.close();
    return nullptr;
}

const Course* CoursesDatabase::findCourseById(unsigned int id) const {
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
        String idStr, courseNameStr, coursePasswordStr, createdByStr;

        getline(ss, idStr, '|');
        getline(ss, courseNameStr, '|');
        getline(ss, coursePasswordStr, '|');
        getline(ss, createdByStr);

        unsigned int currId = std::atoi(idStr.getElements());
        unsigned int currCreatedById = std::atoi(createdByStr.getElements());

        if (currId == id) {
            DBFile.close();
            return new Course(currId, courseNameStr, coursePasswordStr, currCreatedById);
        }
    }

    DBFile.close();
    return nullptr;
}
