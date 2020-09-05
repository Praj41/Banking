//
// Created by ADMIN on 06-07-2020.
//

#pragma once
#include <iostream>
#include "../Bank/Bank.h"
#include "../Customer/Customer.h"

class ATM : public Customer{
private:

public:
    void createAcc(const std::string &name, const std::string &address) {}
    void access(){}
    void addMoney(float) override;                                                 //Overridden functions of class Customer
    void withdrawMoney(float) override;                                            //Overridden functions of class Customer
    void getBalance() override;                                                    //Overridden functions of class Customer
};
