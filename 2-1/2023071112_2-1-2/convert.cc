#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

void convert_case(char* a) {
    for (int i = 0; a[i]; i++) {
        if (isalpha(a[i])) {
            if (islower(a[i])) {
                a[i] = toupper(a[i]);
            } else {
                a[i] = tolower(a[i]);
            }
        }
    }
}

int main() {
    char* inputStr = new char[100];

    while (true) {
        bool validInput = true;

        cin.getline(inputStr, 100);

        if (strcmp(inputStr, "exit") == 0) {
            break;
        }
        
        for (int i = 0; inputStr[i]; i++) {
            if (!isalpha(inputStr[i])) {
                cout << "Error: Wrong input!" << endl;
                validInput = false;
                break;
            }
        }
        if (validInput) {
            convert_case(inputStr);
            cout << inputStr << endl;
        } else {
            break;
        }
    }

    delete[] inputStr; 

    return 0;
}
