//
// Created by ADMIN on 29-08-2020.
//

#include "Admin.h"

data Admin::createAcc(const std::string& name, const std::string& address) {

    unsigned int accNo = accounts++;
    float interest = 5.42f;
    std::cout << "Set new ATM pin:" << std::endl;
    return create(name, address, accNo, interest);
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

void Admin::changePassPin(int ch) {
    try {
        int chance = 3;
        if (ch) {
            std::cout << "Enter current Password" << std::endl;
            auto p = getPass();
            while (true) {
                if (databasePtr1.count(p))
                    break;
                if (!--chance)
                    throw chance;
                std::cout << "Bad Password, please enter another password " << chance << " times left" << std::endl;
                p = getPass();
            }
            std::cout << "Enter new PIN" << std::endl;
            databasePtr2[getPin()] = databasePtr1[p];
        } else {
            std::cout << "Enter current PIN" << std::endl;
            auto p = getPin();
            while (true) {
                if (databasePtr2.count(p))
                    break;
                if (!--chance)
                    throw chance;
                std::cout << "Bad PIN, please enter another PIN " << chance << " times left" << std::endl;
                p = getPin();
            }
            std::cout << "Enter new Password" << std::endl;
            databasePtr1[getPass()] = databasePtr2[p];

            accessByPass();
        }
    }
    catch (int chance) {
        std::cout << "Too many bad attempts" << std::endl;
    }
}
