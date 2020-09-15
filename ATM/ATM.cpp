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
    int choice = 0, chance = 3;
    std::cout << "\n\nEnter:\n" << "0. For Using PIN\n" << "1. For Using password" << std::endl;
    std::cin >> choice;

    try {

        if (choice) {
            std::string p;
            std::cout << "Enter your Password :" << std::endl;

            while (true) {
                p = getPass();
                if (databasePtr1.count(p))
                    break;
                if (!--chance)
                    throw chance;
                std::cout << "Enter Password again " << chance << " times left" << std::endl;
            }

            if (BalanceAmount[databasePtr1[p]] < amt)
                throw BalanceAmount[databasePtr1[p]];
            BalanceAmount[databasePtr1[p]] -= amt;
            std::cout << "Done" << std::endl;

        } else {

            std::cout << "Enter your PIN :" << std::endl;
            unsigned long long int p;

            while (true) {
                p = getPin();
                if (databasePtr2.count(p))
                    break;
                if (!--chance)
                    throw chance;
                std::cout << "Enter PIN again " << chance << " times left" << std::endl;
            }
            if (BalanceAmount[databasePtr2[p]] < amt)                             //Exception handling for low balance while withdrawing
                throw BalanceAmount[databasePtr2[p]];                             //Exception handling for low balance while withdrawing
            BalanceAmount[databasePtr2[p]] -= amt;
            std::cout << "Done" << std::endl;
        }
    }
    catch (double bal) {
        std::cout << "Can not withdraw request denied\nbalance = " << bal << " trying to withdraw = " << amt << std::endl;
        return;
    }
    catch (int chance) {
        std::cout << "Too many bad attempts" << std::endl;
        return;
    }
}

void ATM::addMoney(float amt) {
    int choice = 0, chance = 3;
    std::cout << "\n\nEnter:\n" << "0. For Using PIN\n" << "1. For Using password" << std::endl;
    std::cin >> choice;
    try {
        if (choice) {
            std::cout << "Enter your Password :" << std::endl;
            std::string p;
            while (true) {
                p = getPass();
                if (databasePtr1.count(p))
                    break;
                if (!--chance)
                    throw chance;
                std::cout << "Enter Password again " << chance << " times left" << std::endl;
            }
            BalanceAmount[databasePtr1[p]] += amt;
            std::cout << "Done" << std::endl;
        } else {
            std::cout << "Enter your PIN :" << std::endl;
            unsigned long long int p;
            while (true) {
                p = getPin();
                if (databasePtr2.count(p))
                    break;
                if (!--chance)
                    throw chance;
                std::cout << "Enter PIN again " << chance << " times left" << std::endl;
            }
            BalanceAmount[databasePtr2[p]] += amt;
            std::cout << "Done" << std::endl;
        }
    }
    catch (int chance) {
        std::cout << "Too many bad attempts" << std::endl;
        return;
    }
}
