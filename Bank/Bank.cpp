//
// Created by ADMIN on 29-08-2020.
//

#include "Bank.h"

unsigned int Bank::day = 1;
unsigned int Bank::accounts = 43568468;

void Bank::reCalc() {
    for (auto& [key, bal] : BalanceAmount)
        bal += bal * 0.0542;
}

std::string Bank::hash(std::string& hashable) {
    auto hash1 = std::hash<std::string_view>{}(hashable.substr(0, hashable.size() / 2));
    auto hash2 = std::hash<std::string_view>{}(hashable.substr(hashable.size() / 2));
    std::stringstream stream;
    stream << std::hex << hash1 << hash2 << std::dec;
    return stream.str();
}

inline void Bank::nextDay() {
    day++;
    if (day % 30 == 0)
        nextMonth();
}

inline void Bank::nextMonth() {
    reCalc();
}

inline std::string Bank::getPass() {
    std::string str;
    std::cin >> str;
    return std::string(hash(str));
}

inline unsigned long long Bank::getPin() {
    short int pin;
    std::cin >> pin;
    return std::hash<short int>{} (pin);
}

void Bank::create(const std::string& name, const std::string& address, unsigned int accNo, float interest) {
    account.Name = name;
    account.Address = address;
    account.interestRate = interest;
    account.AccNumber = accNo;
    std::ofstream file("..\\database.txt", std::ios::binary | std::ios::app);


    databasePtr2[getPin()] = accNos;

    std::cout << "Enter a new Password" << std::endl;
    databasePtr1[getPass()] = accNos++;

    file.write((char*)&account, sizeof(Account));


    std::cout << "New Account Created :" << std::endl;
    std::cout << "Balance : 0" << std::endl;
    std::cout << "Name : " << account.Name << std::endl;
    std::cout << "Address : " << account.Address << std::endl;
    std::cout << "Interest Rate : " << account.interestRate << std::endl;
    std::cout << "Account Number : " << account.AccNumber << std::endl;
    file.close();
}

void Bank::accessByPin() {
    std::ifstream file("..\\database.txt", std::ios::binary | std::ios::in);

    std::cout << "Enter pin" <<  std::endl;
    auto p = getPin();
    for (int i = 0; i <= databasePtr2[p] ; ++i)
        file.read((char *)&account, sizeof(Account));

    std::cout << "Name : " << account.Name << std::endl;
    std::cout << "Address : " << account.Address << std::endl;
    std::cout << "Interest Rate : " << account.interestRate << std::endl;
    std::cout << "Account Number : " << account.AccNumber << std::endl;

    file.close();
}

void Bank::accessByPass() {
    try {
        std::ifstream file("..\\database.txt", std::ios::binary | std::ios::in);


        std::cout << "Enter Password" <<  std::endl;
        auto p = getPass();

        for (int i = 0; i <= databasePtr1[p] ; ++i)
            file.read((char *)&account, sizeof(Account));

        if (file.fail())
            throw true;

        file.close();
    }
    catch (bool fail) {
        std::cout << "an error occurred please retry\nIf the error persists clean database.txt and restart application\n";
        return;
    }
    std::cout << "Name : " << account.Name << std::endl;
    std::cout << "Address : " << account.Address << std::endl;
    std::cout << "Interest Rate : " << account.interestRate << std::endl;
    std::cout << "Account Number : " << account.AccNumber << std::endl;
}
