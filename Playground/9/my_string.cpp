#include "my_string.h"

MyString::MyString() {
    this->str = "";
}
MyString::MyString(std::string s) {
    this->str = s;
}
MyString& MyString::operator=(const MyString& b) {
    str = b.str;
    return *this;
}
MyString MyString::operator+(const MyString& b) {
    MyString newMs(str + b.str);
    return newMs;
}
MyString MyString::operator*(const int b) {
    MyString newMs;
    for (int i = 0; i < b; ++i) {
        newMs = newMs + str;
    }
    return newMs;
}

std::ostream& operator<<(std::ostream& out, MyString& my_string) {
    out << my_string.str;
    return out;
}

std::istream& operator>>(std::istream& in, MyString& my_string) {
    in >> my_string.str;
    return in;
}