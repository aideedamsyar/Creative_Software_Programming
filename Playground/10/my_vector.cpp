#include "my_vector.h"

MyVector::MyVector() {
	length = 0;
	a = NULL;
}
MyVector::MyVector(int length) {
	a = new double[length];
	this->length = length;
}
MyVector::~MyVector() {
    delete[] a;
}

MyVector& MyVector::operator=(const MyVector& b) {
	if (a != NULL) delete[] a;
	length = b.length;
	a = new double[length];
	for (int i = 0; i < length; ++i) {
		a[i] = b.a[i];
	}
	return *this;
}
MyVector MyVector::operator+(const MyVector& b) {
	MyVector newMv = *this;
	for (int i = 0; i < b.length; ++i) {
		newMv.a[i] += b.a[i];
	}
	return newMv;
}
MyVector MyVector::operator-(const MyVector& b) {
	MyVector newMv = *this;
	for (int i = 0; i < b.length; ++i) {
		newMv.a[i] -= b.a[i];
	}
	return newMv;
}
MyVector MyVector::operator+(const int b) {
	MyVector newMv = *this;
	for (int i = 0; i < length; ++i) {
		newMv.a[i] += b;
	}
	return newMv;
}
MyVector MyVector::operator-(const int b) {
	MyVector newMv = *this;
	for (int i = 0; i < length; ++i) {
		newMv.a[i] -= b;
	}
	return newMv;
}
std::ostream& operator<< (std::ostream& out, MyVector& b) {
	for (int i = 0; i < b.length; ++i) {
		out << b.a[i] << ' ';
	}
	return out;
}
std::istream& operator>> (std::istream& in, MyVector& b) {
	for (int i = 0; i < b.length; ++i) {
		in >> b.a[i];
	}
	return in;
}