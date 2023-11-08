#include "message.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;


int main() {
    messageBook mb;

    string action;
    while (true) {
        string key, message;

        cin >> action;

        if (action == "add") {
            cin >> key;
            cin.ignore();
            getline(cin, message);
            mb.add(key, message);
        } else if (action == "print") {
            cin >> key;
            mb.print(key);
        } else if (action == "list") {
            mb.list();
        } else if (action == "delete") {
            cin >> key;
            mb.remove(key);
        } else if (action == "quit") {
            break;
        }
    }
    

    return 0;
}

