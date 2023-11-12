#include "sorted.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    SortedArray sa;
    string action;

    while (true) {
        getline(cin, action);

        if (action == "quit") {
            break;
        } else {
            // INPUT HANDLING START
            if (action == "add") {
                string input;
                getline(cin, input);
                int num = 0;
                bool isNegative = false;
                bool hasDigit = false;

                for (auto it = input.begin(); it != input.end(); ++it) {
                    char c = *it;

                    if (isdigit(c)) {
                        num = num * 10 + (c - '0');
                        hasDigit = true;
                    } else if (c == '-' && !hasDigit && !isNegative) {
                        isNegative = true;
                    } else if (hasDigit) {
                        if (isNegative) {
                            num = -num;
                        }
                        sa.AddNumber(num); 
                        num = 0;
                        isNegative = false;
                        hasDigit = false;
                    }
                }

                if (hasDigit) {
                    if (isNegative) {
                        num = -num;
                    }
                    sa.AddNumber(num);
                }
            }
            // INPUT HANDLING END
            else if (action == "ascend") {
                vector<int> ascended = sa.GetSortedAscending();
                for (auto it = ascended.begin(); it != ascended.end(); ++it) {
                    cout << *it << " ";
                }
                cout << endl;
            }
            else if (action == "descend") {
                vector<int> descended = sa.GetSortedDescending();
                for (auto it = descended.begin(); it != descended.end(); ++it) {
                    cout << *it << " ";
                }
                cout << endl;
            }
            else if (action == "max") {
                cout << sa.GetMax() << endl;
            }
            else if (action == "min") {
                cout << sa.GetMin() << endl;
            }
        
        }
        
    }
    return 0;
}