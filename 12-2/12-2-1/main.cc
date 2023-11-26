#include "my_vector.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string action;
    MyVector a, b;
    
    while (cin >> action) {
        if (action == "new") {
            int length;
            cin >> length;
            a = MyVector(length);
            b = MyVector(length);
            
            cout << "enter a" << endl;
            cin >> a;
            cout << "enter b" << endl;
            cin >> b;
        } else if (action == "quit") {
            break;
        } else if (action == "a" || action == "b") {
            string op;
            cin >> op;
            
            if (op == "+") {
                int value;
                cin >> value;
                if (action == "a") {
                    a = a + value;
                } else {
                    b = b + value;
                }
                cout << (action == "a" ? a : b) << endl;
            } else if (op == "-") {
                string operand;
                cin >> operand;
                if (operand == "a") {
                    cout << (action == "a" ? a : b) - a << endl;
                } else {
                    cout << (action == "a" ? a : b) - b << endl;
                }
            }
        }
    }
    
    return 0;
}
