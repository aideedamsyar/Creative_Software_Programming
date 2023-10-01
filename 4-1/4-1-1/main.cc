#include <iostream>
#include "zebra.h"
#include <string>
using namespace std;

int main() {
    Zebra* zebraArray[10];
    string initName;
    int initAge, initNumStripes;
    int currentIndex = 0;

    while (true) {
        cin >> initName;

        if (initName == "0") {
            break;
        }

        if (currentIndex < 10) {
            cin >> initAge >> initNumStripes;
            zebraArray[currentIndex] = new Zebra(initName, initAge, initNumStripes);
            currentIndex++;
        } else {
            break; 
        }
    }

    for (int i = 0; i < currentIndex; ++i) {
        zebraArray[i]->printZebra();
        delete zebraArray[i];
    }

    return 0;
}
