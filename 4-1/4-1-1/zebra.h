#ifndef __ZEBRA_H__ 
#define __ZEBRA_H__
#include <string>
using namespace std;

class Zebra { 
    public:
        Zebra();
        Zebra(string _name, int _age, int _numStripes);
        void printZebra();  

    private:
        string name; 
        int age;
        int numStripes;
};

#endif //__ZEBRA_H__