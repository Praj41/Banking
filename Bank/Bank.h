//
// Created by ADMIN on 29-08-2020.
//

#pragma once

#include <string>
#include <sstream>
#include <string>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <fstream>

struct Account {                                                                    //Struct Account holds account info
    std::string Name;
    std::string Address;
    unsigned int AccNumber;
    float interestRate;
};

class Bank {
private:                                                                          //Private part of class bank
    void reCalc();
    unsigned int accNos{0};
    Account account;

protected:                                                                        //Protected part of class bank
    static std::string getPass();
    static unsigned long long getPin();

public:                                                                           //Public part of class bank
    static unsigned int day;
    std::unordered_map<std::string, fpos_t> databasePtr1;
    std::unordered_map<size_t, fpos_t> databasePtr2;
    std::unordered_map<fpos_t, double> BalanceAmount;

    void nextDay();
    void nextMonth();

    static std::string hash(std::string &hashable);
    static unsigned int accounts;                                                 //static variable used to keep track of total users accounts created

    void create(const std::string &name, const std::string &address, unsigned int accNo, float interest);
    void accessByPin();
    void accessByPass();
};
