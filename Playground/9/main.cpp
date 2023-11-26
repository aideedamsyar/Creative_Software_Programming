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
            cout << "enter a";
            cin >> a;
            cout << "enter b";
            cin >> b;
        } else if (action == "quit") {
            break;
        } else {
            stringstream ss(action);
            string left, op;
            ss >> left >> op;
            if (op == "*") {
                MyString selectedOperand, operationResult;
                int right;
                ss >> right;
                if (left == "a") {
                    selectedOperand = a;
                } else if (left == "b") {
                    selectedOperand = b;
                }
                operationResult = selectedOperand * right;
                cout << operationResult << endl;
            } else if (op == "+") {
                MyString firstOperand, secondOperand, operationResult;
                string rhs;
                ss >> rhs;
                if (left == "a") {
                    firstOperand = a;
                } else if (left == "b") {
                    firstOperand = b;
                } 
                if (rhs == "a") {
                    secondOperand = a;
                } else if (rhs == "b") {
                    secondOperand = b;
                }
                operationResult = firstOperand + secondOperand;
                cout << operationResult << endl;
            }
        }
    }
    return 0;
}