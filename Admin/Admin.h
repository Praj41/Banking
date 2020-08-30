//
// Created by ADMIN on 29-08-2020.
//

#pragma once
#include "../Customer/Customer.h"

class Admin : public Customer{
private:

public:

    void createAcc(const std::string &name, const std::string &address) override;
    void access() override;
    void getBalance(){}
    void addMoney(float){}
    void withdrawMoney(float){}
};
