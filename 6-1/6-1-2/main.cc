#include <iostream>
#include <string>
#include "animal.h"
using namespace std;

int main() {
    Animal* animalArr[10];

    char animalType;
    int count = 0;
    
    while(true) {
        string name, favToy;
        int age, numOfStripe;

        cin >> animalType;
        if (animalType == '0' || count == 10) break;

        if (animalType == 'z'){
            cin >> name >> age >> numOfStripe;
            Animal* zebra = new Zebra(name, age, numOfStripe);
            animalArr[count] = zebra;
            count++;
        } else {
            cin >> name >> age >> favToy;
            Animal* cat = new Cat(name, age, favToy);
            animalArr[count] = cat;
            count++;
        }
    }

    for (int i=0; i<count; i++) {
        animalArr[i]->printInfo();
        delete animalArr[i];
    }
}
