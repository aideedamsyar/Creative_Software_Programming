#include "reply_admin.h"
#include <iostream>
#include <string>
#include <cstdlib> // for atoi

using namespace std;

int main() {
    ReplyAdmin replyAdmin;
    string input;
    while (true) {
        getline(cin, input);
        if (input == "#quit") break;

        if (input.length() >= 7 && input.substr(0, 7) == "#remove") {
            string s = input.substr(8); // Adjusted from 8 as we are now looking at the first 7 characters
            int indices[10];
            int count = 0;
            bool allInvalid = true;

            size_t pos = 0;
            while ((pos = s.find(',')) != string::npos) {
                string token = s.substr(0, pos);
                if (token.find('-') != string::npos) { // range
                    size_t dashPos = token.find('-');
                    int start = stoi(token.substr(0, dashPos));
                    int end = stoi(token.substr(dashPos + 1));
                    if (start < 0) start = 0;
                    if (end >= replyAdmin.getChatCount()) end = replyAdmin.getChatCount() - 1;
                    
                    if (start <= end) {
                        allInvalid = false;
                        replyAdmin.removeChat(start, end);
                    }
                } else {
                    int index = stoi(token);
                    if (index >= 0 && index < replyAdmin.getChatCount()) {
                        indices[count++] = index;
                        allInvalid = false;
                    }
                }
                s.erase(0, pos + 1);
            }

            // Handle the last token
            if (s.find('-') != string::npos) { // range
                size_t dashPos = s.find('-');
                int start = stoi(s.substr(0, dashPos));
                int end = stoi(s.substr(dashPos + 1));
                if (start < 0) start = 0;
                if (end >= replyAdmin.getChatCount()) end = replyAdmin.getChatCount() - 1;

                if (start <= end) {
                    allInvalid = false;
                    replyAdmin.removeChat(start, end);
                }
            } else if (!s.empty()) {
                int index = stoi(s);
                if (index >= 0 && index < replyAdmin.getChatCount()) {
                    indices[count++] = index;
                    allInvalid = false;
                }
            }

            if (allInvalid) {
                cout << "Error!" << endl;
                continue;
            }

            if (count > 0) replyAdmin.removeChat(indices, count); // remove comma-separated indices
        } else {
            replyAdmin.addChat(input);
        }
        replyAdmin.printChats();
    }
    return 0;
}