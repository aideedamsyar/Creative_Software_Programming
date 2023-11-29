#include "my_clock.h"
#include <iostream>

using namespace std;

int main() {
    MyClock clock;
    string action;
    while (cin >> action && action!="quit") {
        if (action == "set") {
            cin >> clock;
        } else if (action == "tick") {
            int s;
            cin >> s;
            clock.Tick(s);
        }
        cout << clock << endl;
    }

    return 0;
}