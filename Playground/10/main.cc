#include "my_vector.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

bool isInteger(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }

    return true;
}

int main(void) {
    MyVector a, b;
    int scalar;
    string secTerm;

    while (1) {
        string fullCommand;
        getline(cin, fullCommand);

        istringstream iss(fullCommand);
        string command;
        iss >> command;

        if (command == "new") {
            int length;
            iss >> length;

            a = MyVector(length);
            b = MyVector(length);

            cout << "enter a" << endl;
            cin >> a;
            cin.ignore();

            cout << "enter b" << endl;
            cin >> b;
            cin.ignore();
        } 
        else if (command == "quit") {
            break;
        } 
        else if (command == "a" || command == "b") {
            string op;
            iss >> op;

            if (op == "+" || op == "-") {
                iss >> secTerm;

                if (isInteger(secTerm)) {
                    scalar = stoi(secTerm);

                    if (command == "a") {
                        cout << (op == "+" ? a + scalar : a - scalar) << endl;
                    } 
                    else if (command == "b") {
                        cout << (op == "+" ? b + scalar : b - scalar) << endl;
                    }
                } 
                else {
                    if (command == "a" && secTerm == "b") {
                        cout << (op == "+" ? a + b : a - b) << endl;
                    }
                    else if (command == "a" && secTerm == "a") {
                        cout << (op == "+" ? a + a : a - a) << endl;
                    }
                    else if (command == "b" && secTerm == "a") {
                        cout << (op == "+" ? b + a : b - a) << endl;
                    }
                    else if (command == "b" && secTerm == "b") {
                        cout << (op == "+" ? b + b : b - b) << endl;
                    }
                }
            } 
        } 
    }

    return 0;
}