#include "intset.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    IntegerSet set;
    string action;

    while (true) {
        cin >> action;
        int num;

        if (action == "add") {
            cin >> num;
            set.AddNumber(num);
        } else if (action == "del") {
            cin >> num;
            set.DeleteNumber(num);
        } else if (action == "get") {
            cin >> num;
            int item = set.GetItem(num);
            cout << (item != -1 ? item : -1) << endl;
            continue;  
        } else if (action == "quit") {
            break;
        }

        vector<int> allNumbers = set.GetAll();
        for (int i = 0; i < allNumbers.size(); i++) {
            cout << allNumbers[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
