#include "intset.h"
#include <vector>
using namespace std;

void IntegerSet::AddNumber(int num) {
    bool found = false;
    for (int i = 0; i < numbers_.size(); ++i) {
        if (numbers_[i] == num) {
            found = true;
            break;
        }
    }
    if (!found) {
        numbers_.push_back(num);
    }
}

void IntegerSet::DeleteNumber(int num) {
    for (int i = 0; i < numbers_.size(); ++i) {
        if (numbers_[i] == num) {
            numbers_.erase(numbers_.begin() + i);
            break; 
        }
    }
}

int IntegerSet::GetItem(int pos) {
    if (pos >= 0 && pos < numbers_.size()) {
        return numbers_[pos];
    }
    return -1;
}

std::vector<int> IntegerSet::GetAll() {
    return numbers_;
}
