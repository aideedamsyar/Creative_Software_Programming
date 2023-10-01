#include "message.h"
#include <iostream>

using namespace std;

MessageBook::MessageBook() {
    for (int i = 0; i < MAX_MESSAGES; ++i) {
        phoneNumbers[i] = -1; // Initialize phoneNumbers array with -1 to indicate empty slots
    }
}

void MessageBook::AddMessage(int number, const string& message) {
    for (int i = 0; i < MAX_MESSAGES; ++i) {
        if (phoneNumbers[i] == -1) {
            phoneNumbers[i] = number;
            messages[i] = message;
            break; // Add message and break out of loop 
        }
    }
}

void MessageBook::DeleteMessage(int number) {
    for (int i = 0; i < MAX_MESSAGES; ++i) {
        if (phoneNumbers[i] == number) {
            phoneNumbers[i] = -1; // Mark slot as empty
            break; // Delete message and break out of loop
        }
    }
}

void MessageBook::PrintMessage(int number) {
    for (int i = 0; i < MAX_MESSAGES; ++i) {
        if (phoneNumbers[i] == number) {
            cout << messages[i] << "\n";
            break;
        }
    }
}

void MessageBook::ListMessages() {
    for (int i = 0; i < MAX_MESSAGES; ++i) {
        if (phoneNumbers[i] != -1) {
            cout << phoneNumbers[i] << ": " << messages[i] << "\n";
        }
    }
}
