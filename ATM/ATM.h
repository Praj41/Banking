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
    data createAcc(const std::string &name, const std::string &address) {return {nullptr, 0, 0};}
    void access(){}
    void changePassPin(int ch){}
    void addMoney(float) override;                                                 //Overridden functions of class Customer
    void withdrawMoney(float) override;                                            //Overridden functions of class Customer
    void getBalance() override;                                                    //Overridden functions of class Customer
};
