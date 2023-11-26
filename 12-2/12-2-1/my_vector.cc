#include "my_vector.h"
#include <algorithm>

using namespace std;

MyVector::MyVector() : length(0), a(nullptr) {}

MyVector::MyVector(int length) : length(max(length, 0)), a(length > 0 ? new int[length] : nullptr) {}

MyVector::MyVector(const MyVector& other) : length(other.length), a(nullptr) {
    if (other.a) {
        a = new int[length];
        copy(other.a, other.a + length, a);
    }
}

MyVector::~MyVector() {
    delete[] a;
}

MyVector& MyVector::operator=(const MyVector& other) {
    if (this != &other) {
        int* temp = new int[other.length];
        delete[] a;
        a = temp;
        length = other.length;
        copy(other.a, other.a + length, a);
    }
    return *this;
}

// Rest of your MyVector class implementation remains the same

MyVector MyVector::operator+(const MyVector& b) {
    int minLength = min(this->length, b.length);
    MyVector result(minLength);
    for (int i = 0; i < minLength; ++i) {
        result.a[i] = this->a[i] + b.a[i];
    }
    return result;
}

MyVector MyVector::operator-(const MyVector& b) {
    int minLength = min(this->length, b.length);
    MyVector result(minLength);
    for (int i = 0; i < minLength; ++i) {
        result.a[i] = this->a[i] - b.a[i];
    }
    return result;
}

MyVector MyVector::operator+(const int b) {
    MyVector result = *this;
    for (int i = 0; i < length; ++i) {
        result.a[i] += b;
    }
    return result;
}

MyVector MyVector::operator-(const int b) {
    MyVector result = *this;
    for (int i = 0; i < length; ++i) {
        result.a[i] -= b;
    }
    return result;
}

ostream& operator<<(ostream& os, const MyVector& b) {
    if (b.a) {
        for (int i = 0; i < b.length; ++i) {
            os << b.a[i] << " ";
        }
    }
    return os;
}

istream& operator>>(istream& is, MyVector& b) {
    for (int i = 0; i < b.length; ++i) {
        if (!(is >> b.a[i])) {
            is.clear();
            is.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter integers only." << endl;
            break;
        }
    }
    return is;
}
