#include <iostream>
#include "Customer/Customer.h"
#include "Admin/Admin.h"
#include "ATM/ATM.h"

int main() {
    Customer* customerAtAdmin = new Admin();                     //Here we create an instance of Admin Class as a interface using runtime polymorphism (Late Binding)
    Customer* customerAtATM = new ATM();                         //Here we create an instance of ATM Class as a interface using runtime polymorphism (Late Binding)
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
                std::string nme, add;                                                    //This is a part to create a new account
                std::cout << "Enter your name" << std::endl;                             //This is a part to create a new account
                std::cin.ignore();                                                       //This is a part to create a new account
                getline(std::cin, nme);                                            //This is a part to create a new account
                std::cout << "Enter your Address" << std::endl;                          //This is a part to create a new account
                getline(std::cin, add);                                            //This is a part to create a new account
                customerAtAdmin->createAcc(nme, add);
                break;
            }
            case 2: {
                customerAtAdmin->access();                                                 //Here we can access or see the account details
                break;
            }
            case 3: {
                customerAtATM->getBalance();                                               //Here we can see the account balance
                break;
            }
            case 4: {
                std::cout << "Enter the Amount to Deposit" << std::endl;
                float amount;
                std::cin >> amount;
                customerAtATM->addMoney(amount);                                         //Here we add or remove money from the account
                break;                                                                   //Here we add or remove money from the account
            }                                                                            //Here we add or remove money from the account
            case 5: {                                                                    //Here we add or remove money from the account
                std::cout << "Enter the Amount to Withdraw" << std::endl;                //Here we add or remove money from the account
                float amount;                                                            //Here we add or remove money from the account
                std::cin >> amount;                                                      //Here we add or remove money from the account
                customerAtATM->withdrawMoney(amount);                                    //Here we add or remove money from the account
                break;
            }
            default : Case = 0;
        }
    }
}
