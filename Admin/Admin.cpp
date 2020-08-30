//
// Created by ADMIN on 29-08-2020.
//

#include "Admin.h"

void Admin::createAcc(const std::string& name, const std::string& address) {
    short int pin;
    unsigned int accNo = accounts++;
    float interest = 5.42;
    std::cout << "Set new ATM pin:" << std::endl;
    std::cin >> pin;
    unsigned int hPin = std::hash<short int>{} (pin);
    create(name, address, accNo, hPin, interest);
    //nextDay();
}
