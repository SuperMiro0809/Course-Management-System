/*
    Name: Miroslav Balev
    №: 9MI0600470
*/

#pragma once

#include <ctime>
#include "../utils/String.h"
#include "User.h"

class Message {
    unsigned int id;
    unsigned int senderId;
    unsigned int recipientId;
    String content;
    std::time_t timestamp;

    public:
        Message() = default;

        Message(unsigned int id, unsigned int senderId, unsigned int recipientId, const String& content, std::time_t timestamp);

        friend std::ostream& operator<<(std::ostream& os, const Message& message);
};