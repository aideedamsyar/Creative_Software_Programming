#include <iostream>
#include <map>
#include <fstream>
#include <string>

using namespace std;

int main() {  
    while (true) {
        string action;
        cin >> action;

        if (action == "s") {
            string textFile;
            cin >> textFile;

            ifstream myfile(textFile);

            string word;
            
            map<string, int> wordCount;

            if (myfile.is_open()) {
                while (myfile >> word) {
                    wordCount[word]++;
                }
                myfile.close();
            }
            
            int max;
            for (auto it=wordCount.begin(); it != wordCount.end(); ++it) {
                if ((it->second) > max) {
                    max = it->second;
                }
            }

            for (const auto& pair : wordCount) {
                if (pair.second == max) {
                cout << pair.first << " " << pair.second << endl;
                }
            }
        } else if (action == "q") {
            break;
        }
    }
        


    return 0;
}