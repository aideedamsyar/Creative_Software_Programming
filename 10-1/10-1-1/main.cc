#include "message.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main() {
    MessageBook mb;
    string action;
    
    while (true) {
        int key;
        string message;

        cin >> action;

        if (action == "add") {
            cin >> key;
            cin.ignore();
            getline(cin, message);
            mb.AddMessage(key, message);
        } else if (action == "print") {
            cin >> key;
            cout << mb.GetMessage(key) << endl;
        } else if (action == "list") {
            vector<int> numbers = mb.GetNumbers();
            for (auto it = numbers.begin(); it != numbers.end(); ++it) {
                int number = *it;
                string message = mb.GetMessage(number);
                cout << number << ": " << message << endl;
            }
        } else if (action == "delete") {
            cin >> key;
            mb.DeleteMessage(key);
        } else if (action == "quit") {
            break;
        }
    }
    
    return 0;
}