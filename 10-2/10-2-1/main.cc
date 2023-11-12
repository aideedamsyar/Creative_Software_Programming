#include "setfunc.h"
#include <iostream>
#include <set>
#include <string>

int main() {

    while (true) {
        string input;
        getline(cin, input);

        if (input == "0") {
            break;
        } else {
            size_t set1End = input.find('}');
            size_t operatorPos = input.find_first_of("*+-", set1End);

            size_t set1Start = input.find('{');
            string set1Str = input.substr(set1Start, set1End - set1Start + 1);

            size_t set2Start = input.find('{', set1End);
            size_t set2End = input.find('}', set2Start);
            string set2Str = input.substr(set2Start, set2End - set2Start + 1);

            set<int> set0 = parseSet(set1Str);
            set<int> set1 = parseSet(set2Str);   

            set<int> result;

            if (input[operatorPos] == '*') {
                result = getIntersection(set0, set1);
            } else if (input[operatorPos] ==  '+') {
                result = getUnion(set0, set1);
            } else if (input [operatorPos] ==  '-') {
                result = getDifference(set0, set1);
            }
            
            printSet(result);
        }     
    }
    return 0;
}





