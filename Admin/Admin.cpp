//
// Created by ADMIN on 29-08-2020.
//

#include "Admin.h"

void Admin::createAcc(const std::string& name, const std::string& address) {

    unsigned int accNo = accounts++;
    float interest = 5.42f;
    std::cout << "Set new ATM pin:" << std::endl;
    create(name, address, accNo, interest);
    //nextDay();
}

void Admin::access() {
    int acc;
    std::cout << "0. to access by password\n" << "1. to access by pin" << std::endl;
    std::cin >> acc;
    if (acc)
        accessByPin();
    else
        accessByPass();
}
