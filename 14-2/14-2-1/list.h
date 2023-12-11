#ifndef __LIST_H__
#define __LIST_H__

#include <iostream>

template<class T>
class Node {
    public:
        T data;
        Node<T>* next;
};

template <class T>
class List {
    private:
        Node<T> *head;
    public:
        List() {
            head = nullptr;
        }
        ~List() {
            while(head) {
                Node<T>* tempNode = head;
                head = head->next;
                delete tempNode;
            }
        }
        List(T* arr, int n_nodes) { //Create a list with n_nodes
        head = nullptr;
            for (int i = n_nodes - 1; i >= 0; i--) {
                push_front(arr[i]);
            }
        }
        void insert_at(int idx, const T& data) {
            Node<T>* newNode = new Node<T>{data, nullptr};

            if (idx == 0) {
                newNode->next = head;
                head = newNode;
            } 
            else {
                Node<T>* n = head;

                for (int i = 0; i < idx - 1 && n; ++i) {
                    n = n->next;
                }

                newNode->next = n->next;
                n->next = newNode;
            }
        }
        void remove_at(int idx) {
            Node<T>* tempNode = nullptr;
            if (idx == 0) {
                tempNode = head;
                head = head->next;
            } 
            else {
                Node<T>* n = head;
                for (int i = 0; i < idx - 1 && n->next; ++i) {
                    n = n->next;
                }

                tempNode = n->next;
                n->next = n->next->next;
            }
            delete tempNode;
        }
        void pop_back() {
            if (!head->next) {
                delete head;
                head = nullptr;
                return;
            }

            Node<T>* n = head;
            while (n->next->next) {
                n = n->next;
            }

            delete n->next;
            n->next = nullptr;
        }
        void push_back(const T& val) {
            Node<T>* newNode = new Node<T>{val, nullptr};

            if (!head) {
                head = newNode;
            }
            else {
                Node<T>* n = head;
                while (n->next) {
                    n = n->next;
                }

                n->next = newNode;
            }
        }
        void pop_front() {
            Node<T>* tempNode = head;
            head = head->next;
            delete tempNode;
        }
        void push_front(const T& val) {
            Node<T>* newNode = new Node<T>{val, head};
            head = newNode; 
        }
        
        template <class U>
        friend std::ostream& operator<<(std::ostream& out, List<U>& rhs); //print out nodes
};

template <class T>
std::ostream& operator<<(std::ostream& out, List<T>& rhs) {
    Node<T>* n = rhs.head;
    while (n) {
        out << n->data;
        if (n->next) {
            out << ",";
        }
        n = n->next;
    }
    return out;
}
    
#endif // __LIST_H__
