#include "calendar.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    MyCalendar mc;
    string action, input;

    while (cin >> action && action != "quit") {
        if (action == "set") {
            cin >> input;
            istringstream iss(input);
            MyCalendar tempCalendar;
            if (iss >> tempCalendar) {
                mc = tempCalendar;
            } else {
                cout << "Invalid date: " << input << endl;
            }
        } else if (action == "next") {
            cin >> input;
            MyCalendar tempCalendar = mc;
            if (input == "day") {
                if (!mc.NextDay()) {
                    mc = tempCalendar;
                    cout << "Invalid date" << endl;
                }
            } else {
                if (!mc.NextDay(stoi(input))) {
                    mc = tempCalendar;
                    cout << "Invalid date" << endl;
                }
            }
        }
        cout << mc << endl;
    }
    return 0;
}
