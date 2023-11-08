#include "message.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

void MessageBook::AddMessage(int number, const string& message) {
    messages_[number] = message;    
}

void MessageBook::DeleteMessage(int number) {
    messages_.erase(number);
}

vector<int> MessageBook::GetNumbers() {
    vector<int> numbers;
    map<int, string>::iterator it;
    for (it = messages_.begin(); it != messages_.end() ; ++it) {
        numbers.push_back(it->first);
    }

    return numbers;
}

const std::string& MessageBook::GetMessage(int number) {
    auto it = messages_.find(number); // Find the number in the map
    if (it != messages_.end()) {
        // If the number is found, return the associated message
        return it->second;
    } else {
        return " "; 
    }
}
