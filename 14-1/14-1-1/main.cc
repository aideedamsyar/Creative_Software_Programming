#include "my_container.h"
#include <iostream>

using namespace std;

int main() {
    int int_size, double_size, string_size;
    cin >> int_size;
MyContainer<int> int_container(int_size);
    cin >> int_container;
    cout << int_container;
    int_container.clear();

    cin >> double_size;
    MyContainer<double> double_container(double_size);
    cin >> double_container;
    cout << double_container;
    double_container.clear();

    cin >> string_size;
    MyContainer<string> string_container(string_size);
    cin >> string_container;
    cout << string_container;
    string_container.clear();

    return 0;
}