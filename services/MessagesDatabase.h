#pragma once

#include "Database.h"

class MessagesDatabase: public Database {
    public:
        explicit MessagesDatabase(const char* dbName);

        void sendMessage(unsigned int sentById, unsigned int receiverId, const String& message) const;

        void deleteReceiverMessages(unsigned int receiverId) const;
};