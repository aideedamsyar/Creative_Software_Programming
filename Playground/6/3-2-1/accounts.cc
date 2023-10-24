#include "accounts.h"
#include <iostream>
using namespace std;

Account::Account() {
    this -> _id = 0;
    this -> _balance = 0;
}
int Account::getID() {
    return this -> _id;
}
int Account::getBalance() {
    return this -> _balance;
}
void Account::setID(int id) {
    this -> _id = id;
}
void Account::setBalance(int b) {
    this -> _balance = b;
}

AccountManager::AccountManager() {
    this -> numOfID = 0;
}
bool AccountManager::createAccount() {
    if (this -> numOfID >= 10) {  
        cout << "Failure!\n";
        return 0;
    }
    int n = numOfID;
    accountArray[n].setID(n);
    accountArray[n].setBalance(0);
    ++numOfID;
    cout << "Success!\n";
    printAccount(n);
}

bool AccountManager::deposit(int id, int amount) {
    if (id >= this -> numOfID || id < 0) { 
        cout <<"Failure!\n";
        return 0;
    }
    int temp = this -> accountArray[id].getBalance() + amount;
    if (temp > 1000000) { 
        cout << "Failure!\n";
        this -> printAccount(id);
        return 0;
    }
    this -> accountArray[id].setBalance(temp);
    cout << "Success!\n";
    this -> printAccount(id);
}
bool AccountManager::withdraw(int id, int amount) {
    if (id >= this -> numOfID || id < 0) { 
        cout << "Failure!\n";
        return 0;
    }
    int temp = this -> accountArray[id].getBalance() - amount;
    if (temp < 0) { 
        cout << "Failure!\n";
        this -> printAccount(id);
        return 1;
    }
    this -> accountArray[id].setBalance(temp);
    cout << "Success!\n";
    this -> printAccount(id);
}
bool AccountManager::transfer(int from, int to, int amount) {
    if (from >= this -> numOfID  || from < 0 || to >= this -> numOfID || to < 0) {
        cout << "Failure!\n";
        return 0;
    }
    else {
        int temp1 = this -> accountArray[from].getBalance() - amount;
        int temp2 = this -> accountArray[to].getBalance() + amount;
        if (temp1 < 0 || temp2 > 1000000) { 
            cout << "Failure!\n";
        }
        else {
            this -> accountArray[from].setBalance(temp1);
            this -> accountArray[to].setBalance(temp2);
            cout << "Success!\n";
        }
    }
    int t1, t2;
    if (from < to) {
        t1 = from;
        t2 = to;
    }
    else {
        t1 = to;
        t2 = from;
    }
    this -> printAccount(t1);
    this -> printAccount(t2);

}
void AccountManager::printAccount(int id) {
    cout << "Balance of user " << id << ": " << this -> accountArray[id].getBalance() << endl; 
}

int AccountManager::getMaxID() {
    int maxID = -1; 

    for (int i = 0; i < numOfID; ++i) {
        int currentID = accountArray[i].getID();
        if (currentID > maxID) {
            maxID = currentID; 
        }
    }

    return maxID;
}
