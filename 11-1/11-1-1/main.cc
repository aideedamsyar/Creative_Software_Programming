#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    stack<char> st;
    bool valid = true;
    while (true) {
        int openCount = 0;
        int closeCount = 0;

        string action;
        cin >> action;
    
        if (action == "e") {
            cin.ignore();
            string input;
            getline(cin, input);
            
            for (char ch : input) {
                st.push(ch);
            }

            while (!st.empty()) {
                if (st.top() == '(') {
                    openCount++;
                } else if (st.top() == ')') {
                    closeCount++;
                }
                st.pop();
            }
            if (openCount == closeCount) {
                cout << "matched" << endl;
            } else {
                cout << "not matched" << endl;
            }  

        } else if (action == "q") {
            break;
        }
    }
}