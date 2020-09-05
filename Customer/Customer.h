//
// Created by ADMIN on 30-08-2020.
//

#pragma once

#include "../Bank/Bank.h"

class Customer : public Bank{                                                 //This is an interface (abstract class) with pure virtual functions
public:                                                                       //This is an interface (abstract class) with pure virtual functions
    virtual void access() = 0;                                                //This is an interface (abstract class) with pure virtual functions
    virtual void createAcc(const std::string&, const std::string&) = 0;       //This is an interface (abstract class) with pure virtual functions
    virtual void getBalance() = 0;                                            //This is an interface (abstract class) with pure virtual functions
    virtual void withdrawMoney(float) = 0;                                    //This is an interface (abstract class) with pure virtual functions
    virtual void addMoney(float) = 0;                                         //This is an interface (abstract class) with pure virtual functions
};
