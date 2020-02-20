//
//  SavingsAcct.h
//  BANKPROJ
//
//  Created by Hasan Qureshi on 7/31/17.
//  Copyright © 2017 Hasan Qureshi. All rights reserved.
//
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#ifndef SavingsAcct_h
#define SavingsAcct_h

class SavingsAcct:public BankAccount
{
public:
    SavingsAcct(int ban, string AcctH, double CB, double AnnualIR);
    double Deposit(double Da);
    double Withdraw(double Wa);
    void MonthlyProc();
private:
    bool Status;
};

SavingsAcct::SavingsAcct(int ban, string AcctH, double CB, double AnnualIR)
:BankAccount (ban, AcctH, CB, AnnualIR)
{
    Status=true;
};

double SavingsAcct::Deposit(double Da)
{
    BankAccount::Deposit(Da);
    
    return CB;
};

double SavingsAcct::Withdraw(double Wa)
{
    if(Status)
    {
        CB-=Wa;
        BankAccount::Withdraw(Wa);
    }
    return CB;
}
void SavingsAcct::MonthlyProc()
{
    
    if(BankAccount::GetNow()>4)
    {
        BankAccount::MonthlyCharge-=(BankAccount::GetNow()-4);//Charges $1 for every withdrawl after 4.
    }
    BankAccount::MonthlyProc();
    if(CB<25.00)
        Status=false;
};









#endif /* SavingsAcct_h */
