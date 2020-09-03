//
// Created by ADMIN on 30-08-2020.
//

#pragma once

#include "../Bank/Bank.h"

class Customer : public Bank{
public:
    virtual void access() = 0;
    virtual void createAcc(const std::string&, const std::string&) = 0;
    virtual void getBalance() = 0;
    virtual void withdrawMoney(float) = 0;
    virtual void addMoney(float) = 0;
};
