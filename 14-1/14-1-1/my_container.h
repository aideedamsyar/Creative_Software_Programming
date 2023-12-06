#ifndef __MY_CONTAINER_H__
#define __MY_CONTAINER_H__

#include <iostream>

template <class T>
class MyContainer {
    public:
        MyContainer(int size) {
            this->n_elements = size;
            obj_arr = new T[size];
        }
        ~MyContainer() {
            delete[] obj_arr;
        }
        void clear() {
            delete[] obj_arr;
            obj_arr = nullptr;
            n_elements = 0;
        }
        int size() {
            return this->n_elements;
        }
        template <class U>
        friend std::istream& operator>> (std::istream& in, MyContainer<U>& b);
        template <class U>
        friend std::ostream& operator<< (std::ostream& out, MyContainer<U>& b);
    protected:
        T* obj_arr = nullptr;
        int n_elements;
};

template <class T>
std::istream& operator>> (std::istream& in, MyContainer<T>& b) {
    for (int i=0; i<b.size(); ++i) {
        in >> b.obj_arr[i];
    }
    
    return in;
}
template <class T>
std::ostream& operator<< (std::ostream& out, MyContainer<T>& b) {
    for (int i=0; i<b.size(); ++i) {
        out << b.obj_arr[i] << " ";
    }
    out << std::endl;
    return out;
}

#endif // __MY_CONTAINER_H__