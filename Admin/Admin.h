//
// Created by ADMIN on 29-08-2020.
//

#pragma once
#include "../Bank/Bank.h"

class Admin : private Bank{
private:

public:

    void createAcc(const std::string &name, const std::string &address);
};
