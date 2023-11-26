#include "my_string.h"
using namespace std;

MyString& MyString::operator=(const string& str) {
    this->str = str;
    return *this;
}

MyString& MyString::operator=(const MyString& b) {
    str = b.str;
    return *this;
}

MyString MyString::operator+(const MyString& b) {
    MyString result;
    result.str = this->str + b.str;
    return result;
}

MyString MyString::operator*(const int b) {
    MyString result;
    if (b > 0) { // Make sure to only continue if b is a positive integer (to avoid infinite loops)
        for (int i = 0; i < b; ++i) {
            result.str += this->str;  
        }
    }
    return result;
}

ostream& operator<<(ostream& os, MyString& my_string) {
    os << my_string.str;
    return os;
}

istream& operator>>(istream& is, MyString& my_string) {
    is >> my_string.str;
    return is;
}


