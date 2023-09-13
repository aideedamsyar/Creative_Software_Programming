#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

void convert_case(char* a) {
    for (int i; *(a+i)!='\0'; i++) {
        if(islower(*(a+i))){
        a[i] = toupper(*(a+i));
    } else {
        a[i] = tolower(*(a+i));
    }
    }
}

int main() {
    char* inputString = new char[100];
    
    while(true){
        cin >> inputString;
        
        if(strcasecmp(inputString, "exit") == 0){
            break;
        }
        
        for(int i=0; inputString[i] != '\0'; i++){
            if(isalpha(inputString[i])){
                convert_case(inputString);       
                cout << inputString << endl;
            } else {
                cout << "Error: Wrong input!" << endl;
                break;
            }
        }

    }

    delete[] inputString;

    return 0;
}