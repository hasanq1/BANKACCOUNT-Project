//
//  main.cpp
//  BANKPROJ
//
//  Created by Hasan Qureshi on 7/31/17.
//  Copyright © 2017 Hasan Qureshi. All rights reserved.
//


#include <iostream>
#include <string>
#include <cmath>
#include "BANkACCT1.h"
#include "SavingsAcct.h"
#include "CheckingAcct.h"
using namespace std;

string name;
int BankNum;
double Balence,SInterest=4.5,CInterest=0.00,DEP,WIT;
CheckingAcct  myCheckAcct(12345, "hasan", 0, CInterest);
SavingsAcct  mySavings(54321,"bob",0,SInterest);

void MainMenu1(){
    cout<<"How much would you like to deposit"<<endl;
    cin>>DEP;
    mySavings.Deposit(DEP);
    cout<<"Thank you for your deposit of:$"<<DEP<<endl
    <<"Your new total balence is:$";
    cout<<mySavings.CB;
    cout<<endl;
}

void MainMenu2(){
    cout<<"How much would you like to deposit"<<endl;
    cin>>DEP;
    myCheckAcct.Deposit(DEP);
    cout<<"Your account now has :$"<<myCheckAcct.CB<<endl;
    cout<<"Thank you for your Deposit.";
    cout<<endl;
}

void MainMenu3(){
    cout<<"How much would you like to withdraw?"<<endl;
    cin>>WIT;
    mySavings.Withdraw(WIT);
    cout<<"Here is your withdrawl of:$"<<WIT<<endl
    <<"Your new total balence is:$";
    cout<<mySavings.CB;
    cout<<endl;
}
void MainMenu4(){
    cout<<"How much would you like to withdraw?"<<endl;
    cin>>WIT;
    myCheckAcct.Withdraw(WIT);
    cout<<"Here is your withdrawl of:$"<<WIT<<endl
    <<"Your new total balence is:$";
    cout<<myCheckAcct.CB;
    cout<<endl;
}
void MainMenu5(){
    
    cout<<"Withdrawals from checking: "<<myCheckAcct.GetNow()<<endl;
    cout<<"Deposits from checking: "<<myCheckAcct.GetNod()<<endl;
    cout<<"Withdrawals from savings: "<<mySavings.GetNow()<<endl;
    cout<<"Deposits from savings: "<<mySavings.GetNod()<<endl;
    
    cout<<"Service charges: $"<<8.15<<endl;
    
    cout<<"Ending balence in checking account  $"<<myCheckAcct.CB<<endl;
    cout<<"Ending balence in Savings Account $"<<mySavings.CB<<endl;
    
    
    
}
void MainMenu6(){
    cout<<endl;
    cout<<"Thank you for your business with us. Good Bye."<<endl;
    return;
}
void MainMenu(){
    char choice;
    do
    {
        cout<<"******** BANK ACCOUNT MENU ********"<<endl
        <<"1.Savings Account Deposit"<<endl
        <<"2.Checking Account Deposit"<<endl
        <<"3.Savings Account Withdrawal"<<endl
        <<"4.Checking Account Withdrawal"<<endl
        <<"5.Update and Display Account Statistics"<<endl
        <<"6.Exit"<<endl;
        cout<<"Your choice, please: (1-6): ";
        cin>>choice;
        switch (choice) {
            case '1':MainMenu1();
                break;
            case '2':MainMenu2();
                break;
            case '3':MainMenu3();
                break;
            case '4':MainMenu4();
                break;
            case '5':MainMenu5();
                break;
            case '6':MainMenu6();
                break;
            default:
                cout<<"Invalid choice choose again";
                break;
        }
        cout<<endl;
    }
    while (choice!='6');
}

int main()
{
    MainMenu();
        return 0;
}
