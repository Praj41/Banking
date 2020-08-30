#include <iostream>
#include "Customer/Customer.h"
#include "Admin/Admin.h"
#include "ATM/ATM.h"

int main() {
    Customer* customerAtAdmin = new Admin();
    Customer* customerAtATM = new ATM();
    int Case = 1;

    while(Case) {
        std::cout << "\n\n\n1. Create account\n"
            << "2. Display details of account\n"
            << "3. Display account Balance\n"
            << "4. Deposit money\n"
            << "5. Withdraw money" << std::endl;
        std::cin >> Case;
        switch (Case) {
            case 1: {
                std::string nme, add;
                std::cout << "Enter your name" << std::endl;
                std::cin.ignore();
                getline(std::cin, nme);
                std::cout << "Enter your Address" << std::endl;
                getline(std::cin, add);
                customerAtAdmin->createAcc(nme, add);
                break;
            }
            case 2: {
                customerAtAdmin->access();
                break;
            }
            case 3: {
                customerAtATM->getBalance();
                break;
            }
            case 4: {
                std::cout << "Enter the Amount to Deposit" << std::endl;
                float amount;
                std::cin >> amount;
                customerAtATM->addMoney(amount);
                break;
            }
            case 5: {
                std::cout << "Enter the Amount to Withdraw" << std::endl;
                float amount;
                std::cin >> amount;
                customerAtATM->withdrawMoney(amount);
                break;
            }
            default : Case = 0;
        }
    }
}

/*
    admin.createAcc("Prajyot Bhamare", "Somewhere");
    admin.createAcc("Prajyot Bhamareyj ", "Somewhereyj f");
    admin.access();
     */