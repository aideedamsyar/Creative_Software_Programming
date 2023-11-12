#include "sorted.h"
#include <iostream>
#include <vector>
#include <sstream>

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
                istringstream iss(input);
                int num;

                while (iss >> num) {  // Extract integers from the input string
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