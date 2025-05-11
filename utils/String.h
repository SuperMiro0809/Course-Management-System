#pragma once

#include <iostream>

static unsigned roundToPowerOfTwo(unsigned v);

class String {
    char* elements;
    int capacity;
    size_t size;

    void resize(int newCapacity);

    void copyFromDynamic(const String& other);

    void freeDynamic();

    public:
      String();

      String(int capacity);

      String(size_t size, const char* initialValue);

      String(const String& other);

      String(size_t size, char c);

      ~String();

      String& operator=(const String& other);

      size_t getSize() const;

      int getCapacity() const;

      const char* getElements() const;

      void popBack();

      void pushBack(char newElement);

      char& at(int index);

      const char& at(int index) const;

      void clear();

      bool empty();

      void shrinkToFit();

      int find(char c) const;

      int find(const char* substr) const;

      int find(const String& substr) const;

      char& operator[](int index);

      const char& operator[](int index) const;

      friend std::istream& operator>>(std::istream& is, String& str);

      String& operator+=(const String& str);

      String& operator+=(const char* str);

      String& operator+=(char c);

      friend bool operator==(const String& lhs, const String& rhs);

      friend bool operator!=(const String& lhs, const String& rhs);

      friend bool operator<(const String& lhs, const String& rhs);

      friend bool operator>(const String& lhs, const String& rhs);

      friend bool operator<=(const String& lhs, const String& rhs);

      friend bool operator>=(const String& lhs, const String& rhs);
};

bool operator==(const String& lhs, const String& rhs);
bool operator!=(const String& lhs, const String& rhs);
bool operator<(const String& lhs, const String& rhs);
bool operator>(const String& lhs, const String& rhs);
bool operator<=(const String& lhs, const String& rhs);
bool operator>=(const String& lhs, const String& rhs);

String operator+(const String& lhs, const String& rhs);
String operator+(const String& lhs, const char* rhs);
String operator+(const char* lhs, const String& rhs);
String operator+(const String& lhs, char rhs);
String operator+(char lhs, const String& rhs);

std::ostream& operator<<(std::ostream& os, const String& str);
std::istream& operator>>(std::istream& is, String& str);
