#include "sorted.h"
#include <vector>
#include <algorithm>

using namespace std;

void SortedArray::AddNumber(int num) {
    numbers_.push_back(num);
}

vector<int> SortedArray::GetSortedAscending() {
    sort(numbers_.begin(), numbers_.end());
    return numbers_;
}

vector<int> SortedArray::GetSortedDescending() {
    sort(numbers_.rbegin(), numbers_.rend());
    return numbers_;
}

int SortedArray::GetMax() {
    vector<int>::iterator it = max_element(numbers_.begin(), numbers_.end());
    return *it;
}

int SortedArray::GetMin() {
    vector<int>::iterator it = min_element(numbers_.begin(), numbers_.end());
    return *it;
}

