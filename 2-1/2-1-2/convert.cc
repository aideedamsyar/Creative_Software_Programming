#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

void convert_case(char* a) {
    while (*a) {
        if (isalpha(*a)) {
            if (islower(*a)) {
                *a = toupper(*a);
            } else {
                *a = tolower(*a);
            }
        }
        a++;
    }
}

int main() {
    char* string = new char[100];

    while (true) {
        cin.getline(string, 100);

        if (strcasecmp(string, "exit") == 0) {
            break;
        }

        bool validInput = true;
        for (int i = 0; string[i]; i++) {
            if (!isalpha(string[i])) {
                cout << "Error: Wrong input!" << endl;
                validInput = false;
                break;
            }
        }

        if (validInput) {
            convert_case(string);
            cout << string << endl;
        }
    }

    delete[] string; 

    return 0;
}