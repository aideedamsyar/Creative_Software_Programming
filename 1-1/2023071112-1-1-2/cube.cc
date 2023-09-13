#include <iostream>
using namespace std;

int cube(const int* pd) {
    return (*pd) * (*pd) * (*pd);
}

int main() {
    int num;
    cin >> num;
    cout << cube(&num) << endl;
    return 0;
}