#include "setfunc.h"
#include <set>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

// Parse string into a set of integer
// string -> set<int>
set<int> parseSet(const std::string& str) {
    set<int> result;
    int currentNumber = 0;
    bool isNumber = false;
    bool isNegative = false;

    for (int i = 0; i < str.length(); ++i) {
        char ch = str[i];

        if (ch == '-' && !isNumber) {
            isNegative = true;
            continue;
        }

        if (isdigit(ch)) {
            currentNumber = currentNumber * 10 + (ch - '0');
            isNumber = true;
        } else {
            if (isNumber) {
                if (isNegative) {
                    currentNumber = -currentNumber;
                    isNegative = false;
                }
                result.insert(currentNumber);
                currentNumber = 0;
                isNumber = false;
            }
        }
    }

    if (isNumber) {
        if (isNegative) {
            currentNumber = -currentNumber;
        }
        result.insert(currentNumber);
    }

    return result;
}


void printSet(const set<int>& s) {
    cout << "{ ";
    for (auto it=s.begin(); it!=s.end(); ++it) {
        cout << *it << " ";
    }
    cout << "}" << endl;
}

set<int> getIntersection(const set<int>& set0, const set<int>& set1) {
    set<int> result;

    auto it0 = set0.begin();
    auto it1 = set1.begin();

    while (it0 != set0.end() && it1 != set1.end()) {
        if (*it0 < *it1) {
            ++it0;
        } else if (*it1 < *it0) {
            ++it1;
        } else {
            result.insert(*it1);
            ++it0;
            ++it1;
        }
    }
    return result;
}


set<int> getUnion(const set<int>& set0, const set<int>& set1) {
    set<int> result;

    result.insert(set0.begin(), set0.end());
    result.insert(set1.begin(), set1.end());

    return result;
}

set<int> getDifference(const set<int>& set0, const set<int>& set1) {
    set<int> result;

    for (auto it=set0.begin(); it != set0.end(); ++it) {
        if (set1.find(*it) == set1.end()) {
            // If the element is not found in set1, add to result
            result.insert(*it);
        }
    }

    return result;
}

