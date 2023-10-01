#include "reply_admin.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    ReplyAdmin replyAdmin;
    string input;
    while (true) {
        getline(cin, input);
        if (input == "#quit") break;

        if (input.length() >= 7 && input.substr(0, 7) == "#remove") {
            string s = input.substr(8);
            int indices[10];
            int count = 0;
            bool allInvalid = true;

            int start = 0;
            int pos = 0;
            while ((pos = s.find(',', start)) != string::npos) {
                string piece = s.substr(start, pos - start);
                int dashPos = piece.find('-');
                if (dashPos != string::npos) { 
                    int startRange = stoi(piece.substr(0, dashPos));
                    int endRange = stoi(piece.substr(dashPos + 1));
                    if (startRange < 0) startRange = 0;
                    if (endRange >= replyAdmin.getChatCount()) endRange = replyAdmin.getChatCount() - 1;

                    if (startRange <= endRange) {
                        allInvalid = false;
                        replyAdmin.removeChat(startRange, endRange);
                    }
                } else {
                    int index = stoi(piece);
                    if (index >= 0 && index < replyAdmin.getChatCount()) {
                        indices[count++] = index;
                        allInvalid = false;
                    }
                }
                start = pos + 1;
            }

            string lastPiece = s.substr(start);
            int dashPos = lastPiece.find('-');
            if (dashPos != string::npos) { 
                int startRange = stoi(lastPiece.substr(0, dashPos));
                int endRange = stoi(lastPiece.substr(dashPos + 1));
                if (startRange < 0) startRange = 0;
                if (endRange >= replyAdmin.getChatCount()) endRange = replyAdmin.getChatCount() - 1;

                if (startRange <= endRange) {
                    allInvalid = false;
                    replyAdmin.removeChat(startRange, endRange);
                }
            } else if (!lastPiece.empty()) {
                int index = stoi(lastPiece);
                if (index >= 0 && index < replyAdmin.getChatCount()) {
                    indices[count++] = index;
                    allInvalid = false;
                }
            }

            if (allInvalid) {
                cout << "Error!" << endl;
                continue;
            }

            if (count > 0) replyAdmin.removeChat(indices, count); 
        } else {
            replyAdmin.addChat(input);
        }
        replyAdmin.printChats();
    }
    return 0;
}
