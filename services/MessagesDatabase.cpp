#include "MessagesDatabase.h"

#include <fstream>
#include <ctime>

MessagesDatabase::MessagesDatabase(const char* dbName): Database(dbName) {}

void MessagesDatabase::sendMessage(unsigned int sentById, unsigned int receiverId, const String& message) const {
    int nextId = autoIncrement();

    std::ofstream DBFile(dbName.getElements(), std::ios::app);

    if (!DBFile.is_open()) {
        throw std::runtime_error("Error: could not open database file");
    }

    std::time_t now = std::time(nullptr);

    DBFile << nextId << '|';
    DBFile << sentById << '|';
    DBFile << receiverId << '|';
    DBFile << message << '|';
    DBFile << now << '\n';

    DBFile.close();
}
