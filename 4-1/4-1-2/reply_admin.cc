#include "reply_admin.h"
#include <iostream>
#include <cstring> 

ReplyAdmin::ReplyAdmin() {
    chats = new std::string[NUM_OF_CHART];
    num_chats = 0; 
}

ReplyAdmin::~ReplyAdmin() {
    delete[] chats;
}

int ReplyAdmin::getChatCount() {
    return num_chats;
}

bool ReplyAdmin::addChat(std::string _chat) {
    if (num_chats >= NUM_OF_CHART) return false;
    chats[num_chats++] = _chat;
    return true;
}

bool ReplyAdmin::removeChat(int _index) {
    if (_index < 0 || _index >= num_chats) return false;
    for (int i = _index; i < num_chats - 1; ++i) {
        chats[i] = chats[i + 1];
    }
    num_chats--;
    return true;
}

bool ReplyAdmin::removeChat(int *_indices, int _count) {
    bool removed = false;
    for(int i=0; i<_count; i++) {
        for(int j=i+1; j<_count; j++) {
            if(_indices[j] > _indices[i]) std::swap(_indices[j], _indices[i]);
        }
    }
    for (int i = 0; i < _count; ++i) {
        if (removeChat(_indices[i])) removed = true;
    }
    return removed;
}

bool ReplyAdmin::removeChat(int _start, int _end) {
    bool removed = false;
    for (int i = _end; i >= _start; --i) {
        if (removeChat(i)) removed = true;
    }
    return removed;
}

void ReplyAdmin::printChats() {
    for (int i = 0; i < num_chats; ++i) {
        std::cout << i << " " << chats[i] << std::endl;
    }
}
