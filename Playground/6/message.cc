#include "message.h"
#include <map>
using namespace std;

messageBook::messageBook() {}

void messageBook::add(string key, string message) {
    m.insert(make_pair(key, message));
}

void messageBook::print(string key) {
    it = m.find(key);
    cout << it->second << endl;
}

void messageBook::list() {
    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }
}

void messageBook::remove(string key) {
    m.erase(key);
}

