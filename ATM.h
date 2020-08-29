//
// Created by ADMIN on 06-07-2020.
//

#pragma once
#include <iostream>

class ATM {
private:
    short PIN;
    int numOfTran;
    double bal;
    double lastTran[10];                //Stores last 10 transactions amounts
    std::string name;
    bool loginSuccessFull = false;      //Allow banking only if true, set true in void AccountLogin();

public:
    void showBal();
    ATM();


    void Deposit();                                   //Allow money deposit                                              Implement these functions.
    void Withdraw();                                  //Allow money withdraw                                             Implement these functions.
    void changePIN();                                 //Allow PIN change                                                 Implement these functions.
    void displayAccInfo();                            //Display Holder name bal and last 10 transactions                 Implement these functions.
    void printTrans();                                //Prints last 10 transactions amounts                              Implement these functions.
    void AccountLogin(std::string cname, int cPIN);   //Account login with Customer_name and Customer_PIN                Implement these functions.
};
