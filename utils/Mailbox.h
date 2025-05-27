#pragma once

#include <iostream>
#include "../models/Message.h"

class Mailbox {
    Message* messages;
    size_t size;
    size_t capacity;

    void freeDynamic();

    void copyDynamic(const Mailbox& other);

    void resize(size_t newCapacity);

    public:
        Mailbox();

        Mailbox(const Mailbox& other);

        Mailbox& operator=(const Mailbox& other);

        ~Mailbox();

        void addMessage(const Message& msg);

        size_t getSize() const;

        void loadFromFile(const char* filename, unsigned int userId);

        friend std::ostream& operator<<(std::ostream& os, const Mailbox& message);
};