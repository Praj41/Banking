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

struct Account {
    std::string Name, Address;
    unsigned int AccNumber;
    float interestRate;
    Account(std::string name, std::string address, unsigned int accNo, float interest)
        : Name(std::move(name)), Address(std::move(address)), AccNumber(accNo), interestRate(interest){};
};

class Bank {
private:
    void reCalc();
    Account *account;
    static std::string getPass();
public:
    static unsigned int day;
    std::unordered_map<std::string, fpos_t> databasePtr1;
    std::unordered_map<unsigned int, fpos_t> databasePtr2;

    void nextDay();
    void nextMonth();

    static std::string hash(std::string &hashable);
    static unsigned int accounts;

    void create(const std::string &name, const std::string &address, unsigned int accNo, unsigned int pin, float interest);
};
