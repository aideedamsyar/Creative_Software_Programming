#ifndef __MESSAGE_H__ 
#define __MESSAGE_H__

#include <iostream>
#include <map>
#include <vector>
#include <string>

class MessageBook { 
    public:
        void AddMessage(int number, const std::string& message); 
        void DeleteMessage(int number);
        std::vector<int> GetNumbers();
        const std::string& GetMessage(int number);
    private:
    std::map<int, std::string> messages_;
};

#endif //__MESSAGE_H__