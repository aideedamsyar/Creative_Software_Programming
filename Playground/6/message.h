#ifndef __MESSAGE_H_
#define __MESSAGE_H_

#include <iostream>
#include <string>
#include <map>

using namespace std;

class messageBook {
    public:
        messageBook();
        void add(string key, string message);
        void print(string key);
        void list();
        void remove(string key);
    private:
        map <string, string> m;
        map <string, string>::iterator it;
};












#endif // __MESSAGE_H_