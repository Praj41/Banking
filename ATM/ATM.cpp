//
// Created by ADMIN on 06-07-2020.
//

#include "ATM.h"

void ATM::getBalance() {
    int choice = 0;
    std::cout << "\n\nEnter:\n" << "0. For Using PIN\n" << "1. For Using password" << std::endl;
    std::cin >> choice;
    if(choice)
        std::cout << "Enter your Password :" << BalanceAmount[databasePtr1[getPass()]] << " is your Account Balance" << std::endl;
    else
        std::cout << "Enter your PIN :" << BalanceAmount[databasePtr2[getPin()]] << " is your Account Balance" << std::endl;
}

void ATM::withdrawMoney(float amt) {
    int choice = 0;
    std::cout << "\n\nEnter:\n" << "0. For Using PIN\n" << "1. For Using password" << std::endl;
    std::cin >> choice;
    try {
        if (choice) {
            std::cout << "Enter your Password :" << std::endl;
            auto p = getPass();
            if (BalanceAmount[databasePtr1[p]] < amt)
                throw BalanceAmount[databasePtr1[p]];
            BalanceAmount[databasePtr1[p]] -= amt;
            std::cout << "Done" << std::endl;
        } else {
            std::cout << "Enter your PIN :" << std::endl;
            auto p = getPin();
            if (BalanceAmount[databasePtr2[p]] < amt)
                throw BalanceAmount[databasePtr2[p]];
            BalanceAmount[databasePtr2[p]] -= amt;
            std::cout << "Done" << std::endl;
        }
    }
    catch (double bal) {
        std::cout << "Can not withdraw request denied\nbalance = " << bal << " trying to withdraw = " << amt << std::endl;
        return;
    }
}

void ATM::addMoney(float amt) {
    int choice = 0;
    std::cout << "\n\nEnter:\n" << "0. For Using PIN\n" << "1. For Using password" << std::endl;
    std::cin >> choice;
    if(choice) {
        std::cout << "Enter your Password :" << std::endl;
        BalanceAmount[databasePtr1[getPass()]] += amt;
        std::cout << "Done" << std::endl;
    }
    else {
        std::cout << "Enter your PIN :" << std::endl;
        BalanceAmount[databasePtr2[getPin()]] += amt;
        std::cout << "Done" << std::endl;
    }
}
