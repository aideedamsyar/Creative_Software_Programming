#include "my_vector.h"
#include <iostream>
#include <sstream>
#include <string>

#include "my_vector.h"
#include <iostream>
#include <sstream>
#include <string>

int main() {
    MyVector *a = nullptr, *b = nullptr;  // Initialize pointers to nullptr

    std::string q;
    for (;;) {
        std::getline(std::cin, q);

        if (q.substr(0, 3) == "new") {
            int length;
            std::stringstream ss(q.substr(3));
            ss >> length;

            // Cleanup existing objects if they have been allocated
            if (a != nullptr) {
                delete a;
                a = nullptr;  // Reset pointer to nullptr
            }
            if (b != nullptr) {
                delete b;
                b = nullptr;  // Reset pointer to nullptr
            }

            // Allocate new objects
            a = new MyVector(length);
            b = new MyVector(length);

            std::cout << "enter a\n";
            std::cin >> *a;
            std::cout << "enter b\n";
            std::cin >> *b;
        } else if (q == "quit") {
            break;
        } else {
            std::stringstream ss(q);
            std::string l, op;
            ss >> l >> op;
            if (op == "-") {
                MyVector nmv, pmv;
                std::string r;
                ss >> r;
                if (l == "a") nmv = *a;
                else if (l == "b") nmv = *b;
                if (r == "a") pmv = nmv - *a;
                else if (r == "b") pmv = nmv - *b;
                else {
                    int x;
                    std::stringstream sr(r);
                    sr >> x;
                    pmv = nmv - x;
                }
                std::cout << pmv << '\n';
            } else if (op == "+") {
                MyVector nmv, pmv;
                std::string r;
                ss >> r;
                if (l == "a") nmv = *a;
                else if (l == "b") nmv = *b;
                if (r == "a") pmv = nmv + *a;
                else if (r == "b") pmv = nmv + *b;
                else {
                    int x;
                    std::stringstream sr(r);
                    sr >> x;
                    pmv = nmv + x;
                }
                std::cout << pmv << '\n';
            }
        }
    }

    // Cleanup at the end
    delete a;
    delete b;

    return 0;
}
