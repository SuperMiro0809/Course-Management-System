#include "Mailbox.h"

#include <fstream>
#include <sstream>

void Mailbox::freeDynamic() {
    delete[] messages;
}

void Mailbox::copyDynamic(const Mailbox& other) {
    Message* newMessages = new Message[other.capacity];

    for (size_t i = 0; i < other.size; i++) {
        newMessages[i] = other.messages[i];
    }

    delete[] messages;
    messages = newMessages;
}

void Mailbox::resize(size_t newCapacity) {
    Message* temp = new Message[newCapacity];

    for (size_t i = 0; i < size; i++) {
        temp[i] = messages[i];
    }

    delete[] messages;
    messages = temp;
}

Mailbox::Mailbox() {
    size = 0;
    capacity = 8;
    messages = new Message[capacity];
}

Mailbox::Mailbox(const Mailbox& other) {
    size = other.size;
    capacity = other.capacity;
    copyDynamic(other);
}

Mailbox& Mailbox::operator=(const Mailbox& other) {
    if (this != &other) {
        freeDynamic();
        size = other.size;
        capacity = other.capacity;
        copyDynamic(other);
    }

    return *this;
}

Mailbox::~Mailbox() {
    freeDynamic();
}

size_t Mailbox::getSize() const {
    return size;
}

void Mailbox::addMessage(const Message& msg) {
    if (size >= capacity) {
        resize(capacity * 2);
    }

    messages[size++] = msg;
}

void Mailbox::loadFromFile(const char* filename, unsigned int userId) {
    std::ifstream MessagesDB(filename);
    if (!MessagesDB.is_open()) {
        return;
    }

    String line;
    while (true) {
        getline(MessagesDB, line);

        if (MessagesDB.eof()) {
            break;
        }

        std::stringstream ss(line.getElements());
        String idStr, senderIdStr, receiverIdStr, messageStr, timeStr;

        getline(ss, idStr, '|');
        getline(ss, senderIdStr, '|');
        getline(ss, receiverIdStr, '|');
        getline(ss, messageStr, '|');
        getline(ss, timeStr);

        unsigned int currId = std::atoi(idStr.getElements());
        unsigned int senderId = std::atoi(senderIdStr.getElements());
        unsigned int receiverId = std::atoi(receiverIdStr.getElements());
        std::time_t timestamp = std::atoll(timeStr.getElements());

        if (receiverId == userId) {
            addMessage(Message(currId, senderId, receiverId, messageStr, timestamp));
        }
    }

    MessagesDB.close();
}

std::ostream& operator<<(std::ostream& os, const Mailbox& message) {
    for (size_t i = 0; i < message.getSize(); i++) {
        os << message.messages[i] << '\n';
    }

    return os;
}