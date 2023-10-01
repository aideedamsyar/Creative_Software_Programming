#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

class MessageBook {
public:
    static const int MAX_MESSAGES = 10;

    MessageBook();

    void AddMessage(int number, const std::string& message);
    void DeleteMessage(int number);
    void PrintMessage(int number);
    void ListMessages();

private:
    int phoneNumbers[MAX_MESSAGES];
    std::string messages[MAX_MESSAGES];
};

#endif
