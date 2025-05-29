#include "MessagesDatabase.h"

#include <fstream>
#include <ctime>
#include <sstream>

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

void MessagesDatabase::deleteReceiverMessages(unsigned int receiverId) const {
    std::ifstream DBFile(dbName.getElements());
    if (!DBFile.is_open()) {
        throw std::runtime_error("Error: could not open database file");
    }

    std::ofstream TempFile("../messages_temp.txt");
    if (!TempFile.is_open()) {
        throw std::runtime_error("Error: could not open temporary file for writing");
    }

    String line;
    while (true) {
        getline(DBFile, line);

        if (DBFile.eof()) {
            break;
        }

        std::stringstream ss(line.getElements());
        String idStr, senderIdStr, receiverIdStr;

        getline(ss, idStr, '|');
        getline(ss, senderIdStr, '|');
        getline(ss, receiverIdStr, '|');

        unsigned int currentReceiverId = std::atoi(receiverIdStr.getElements());

        if (currentReceiverId != receiverId) {
            TempFile << line << '\n';
        }
    }

    DBFile.close();
    TempFile.close();

    std::remove(dbName.getElements());
    std::rename("../messages_temp.txt", dbName.getElements());
}