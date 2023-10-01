#include <iostream>
#include "accounts.h"
using namespace std;

int main() {
    AccountManager manager;
    char input;

    while (1) {
        cout << "Job?" << endl;
        cin >> input;
        if (input == 'N') {
            manager.createAccount();
        }
        else if (input == 'D') {
            int id, amount;
            cin >> id >> amount;
            manager.deposit(id, amount);
        }
        else if (input == 'W') {
            int id, amount;
            cin >> id >> amount;
            manager.withdraw(id, amount);
        }
        else if (input == 'T') {
            int from, to, amount;
            cin >> from >> to >> amount;
            manager.transfer(from, to, amount);
        }
        else if (input == 'Q') 
            break;
    }
    return 0;
}
