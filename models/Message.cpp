/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#include "Message.h"

#include "../services/UsersDatabase.h"

Message::Message(unsigned int id, unsigned int senderId, unsigned int recipientId, const String& content, std::time_t timestamp):
    id(id),
    senderId(senderId),
    recipientId(recipientId),
    content(content),
    timestamp(timestamp) {}

std::ostream& operator<<(std::ostream& os, const Message& message) {
    std::tm* timeinfo = std::localtime(&message.timestamp);
    char buffer[100];
    std::strftime(buffer, sizeof(buffer), "%H:%M %d.%m.%Y", timeinfo);

    UsersDatabase usersDb("../users.txt");
    const User* sender = usersDb.getUserById(message.senderId);
    String senderName;

    if (sender) {
        senderName = sender->getFirstName() + " " + sender->getFamilyName();
        delete sender;
    }

    os << buffer << ", sent by " << senderName << ": " << message.content;
    return os;
}
