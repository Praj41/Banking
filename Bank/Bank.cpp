//
// Created by ADMIN on 29-08-2020.
//

#include "Bank.h"

unsigned int Bank::day = 1;
unsigned int Bank::accounts = 43568468;

void Bank::reCalc() {

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

std::string Bank::getPass() {
    std::cout << "Enter a new Password" << std::endl;
    std::string str;
    std::cin >> str;
    return std::string(hash(str));
}

void Bank::create(const std::string& name, const std::string& address, unsigned int accNo, unsigned int pin, float interest) {
    account = new Account(name, address, accNo, interest);
    std::ofstream file("../database.Dat", std::ios::app | std::ios::binary);

    std::string password = getPass();

    databasePtr1[password] = file.tellp();
    databasePtr2[pin] = file.tellp();

    file.write((char*)account, sizeof(Account));
    file.close();
}
