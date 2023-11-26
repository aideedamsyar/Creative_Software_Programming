#include "my_vector.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    MyVector a, b;
    string action;

    while (cin >> action && action != "quit") {
        if (action == "new") {
            int length;
            cin >> length;

            a = MyVector(length);
            b = MyVector(length);

            cout << "enter a" << endl;
            cin >> a;
            cout << "enter b" << endl;
            cin >> b;
        } else if (action == "a" || action == "b") {
            string op;
            cin >> op;

            if (op == "+" || op == "-") {
                string rightOperand;
                cin >> rightOperand;

                if (isdigit(rightOperand[0])) { 
                    int addSubstractValue = stoi(rightOperand);

                    cout << (action == "a" ? (op == "+" ? a + addSubstractValue : a - addSubstractValue) : (op == "+" ? b + addSubstractValue : b - addSubstractValue)) << endl;
                } 
                else {
                    if (rightOperand == "a") {
                        cout << (action == "a" ? (op == "+" ? a + a : a - a) : (op == "+" ? b + a : b - a)) << endl;
                    } 
                    else if (rightOperand == "b") {
                        cout << (action == "a" ? (op == "+" ? a + b : a - b) : (op == "+" ? b + b : b - b)) << endl;
                    }
                }
            }
        }
    }

    return 0;
}
