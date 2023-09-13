#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;

    if (num >= 0) {
        cout << num << "is more than zero" << endl;
    } else {
        cout << num << "is less than zero" << endl;
    }

    return 0;
}