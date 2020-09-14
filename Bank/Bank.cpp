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
    std::stringstream stream;                                                                               //Returns a quick hash of the entered password for security
    stream << std::hex << hash1 << hash2 << std::dec;                                                       //Returns a quick hash of the entered password for security
    return stream.str();                                                                                    //Returns a quick hash of the entered password for security
}

inline void Bank::nextDay() {
    day++;
    if (day % 30 == 0)
        nextMonth();
}

inline void Bank::nextMonth() {
    reCalc();
}

inline std::string Bank::getPass() {                                      //Gets password from user
    std::string str;                                                      //Gets password from user
    std::cin >> str;                                                      //Gets password from user
    return std::string(hash(str));
}

inline unsigned long long Bank::getPin() {                                 //Gets PIN from user
    short int pin;                                                         //Gets PIN from user
    std::cin >> pin;                                                       //Gets PIN from user
    return std::hash<short int>{} (pin);
}

data Bank::create(const std::string& name, const std::string& address, unsigned int accNo, float interest) {
    account.Name = name;
    account.Address = address;
    account.interestRate = interest;
    account.AccNumber = accNo;
    std::ofstream file("..\\database.txt", std::ios::binary | std::ios::app);
    unsigned long long int p1;
    std::string p2;

    try {
        int chance = 5;
        while (true) {
            p1 = getPin();
            if (!databasePtr2.count(p1))
                break;
            if (!--chance)
                throw chance;
            std::cout << "Bad PIN please enter another PIN " << chance << " times left" << std::endl;
        }
        std::cout << "Enter a new Password" << std::endl;
        chance = 5;
        while (true) {
            p2 = getPass();
            if (!databasePtr1.count(p2))
                break;
            if (!--chance)
                throw chance;
            std::cout << "Bad Password please enter another password " << chance << " times left" << std::endl;
        }
        databasePtr2[p1] = accNos;
        databasePtr1[p2] = accNos;
    }
    catch (int chance) {
        std::cout << "Too many bad attempts" << std::endl;
        file.close();
        return {0, 0, 0};
    }
    file.write((char*)&account, sizeof(Account));


    std::cout << "New Account Created :" << std::endl;
    std::cout << "Balance : 0" << std::endl;
    std::cout << "Name : " << account.Name << std::endl;
    std::cout << "Address : " << account.Address << std::endl;
    std::cout << "Interest Rate : " << account.interestRate << std::endl;
    std::cout << "Account Number : " << account.AccNumber << std::endl;
    file.close();
    return {p2, p1, accNo++};
}

void Bank::accessByPin() {
    std::ifstream file("..\\database.txt", std::ios::binary | std::ios::in);

    std::cout << "Enter pin" <<  std::endl;
    auto p = getPin();                                                                         //Displays the user info using entered PIN
    for (int i = 0; i <= databasePtr2[p] ; ++i)                                                //Displays the user info using entered PIN
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
                                                                                            //Displays user info using entered password with exception handling
        if (file.fail())                                                                    //Displays user info using entered password with exception handling
            throw true;                                                                     //Displays user info using entered password with exception handling

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
