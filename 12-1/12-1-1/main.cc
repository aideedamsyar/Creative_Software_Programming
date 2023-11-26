#include "my_string.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string action;
    MyString a, b;
    while (true) {
        getline(cin, action);
        if (action == "new") {
            cout << "enter a" << endl; 
            cin >> a;
            cout << "enter b" << endl; 
            cin >> b;
        } else if (action == "quit") {
            break;
        } else {
            stringstream ss(action);
            string left, op;
            ss >> left >> op;
            if (op == "*") {
                MyString operand1, operationResult;
                int right;
                ss >> right;
                operand1 = (left == "a") ? a : b; 
                operationResult = operand1 * right;
                cout << operationResult << endl;
            } else if (op == "+") {
                MyString operand1, operand2, operationResult;
                string secondOperandName;
                ss >> secondOperandName;
                operand1 = (left == "a") ? a : b; 
                operand2 = (secondOperandName == "a") ? a : b; 
                operationResult = operand1 + operand2;
                cout << operationResult << endl;
            }
        }
    }
    return 0;
}
