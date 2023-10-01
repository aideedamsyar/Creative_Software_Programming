#include "message.h"
#include <iostream>

using namespace std;

int main() {
    MessageBook mb;
    while (true) {
        string operation;
        cin >> operation;

        if (operation == "add") {
            int phoneNumber;
            string message;
            cin >> phoneNumber;
            cin.ignore(); // To consume the newline character
            getline(cin, message);
            mb.AddMessage(phoneNumber, message);
        }
        else if (operation == "delete") {
            int phoneNumber;
            cin >> phoneNumber;
            mb.DeleteMessage(phoneNumber);
        }
        else if (operation == "print") {
            int phoneNumber;
            cin >> phoneNumber;
            mb.PrintMessage(phoneNumber);
        }
        else if (operation == "list") {
            mb.ListMessages();
        }
        else if (operation == "quit") {
            break;
        }
    }

    return 0;
}
