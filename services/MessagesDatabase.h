#pragma once

#include "Database.h"

class MessagesDatabase: public Database {
    public:
        MessagesDatabase(const char* dbName);

        void sendMessage(unsigned int sentById, unsigned int receiverId, const String& message) const;
};