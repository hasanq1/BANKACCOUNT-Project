//
//  CheckingAcct.h
//  BANKPROJ
//
//  Created by Hasan Qureshi on 7/31/17.
//  Copyright © 2017 Hasan Qureshi. All rights reserved.
//

#ifndef CheckingAcct_h
#define CheckingAcct_h

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class CheckingAcct: public BankAccount
{
    public:
        CheckingAcct(int ban, string AcctH, double CB, double AnnualIR);
        double Deposit(double Da);
        double Withdraw(double Wa);
        void MonthlyProc();
    private:
        bool Status;
        double C,C2;
};


CheckingAcct::CheckingAcct(int ban, string AcctH, double CB, double AnnualIR)
:BankAccount(ban, AcctH, CB, AnnualIR)
{
    Status=true;
};

double CheckingAcct::Deposit(double Da)
{
    BankAccount::Deposit(Da);
    
    return CB;
};

double CheckingAcct::Withdraw(double Wa)
{
    if(Wa<=CB)
    {
        BankAccount::Withdraw(Wa);
    }
    else
    {
        CB-=15;
        BankAccount::Withdraw(Wa);
        cout<<"You owe $"<<(-1*CB)<<" due to $15 service charge."<<endl;
    }
    return CB;
};

void CheckingAcct::MonthlyProc()
{
    
    C=BankAccount::GetNow();
    C2=(C*.10)+5;
    CB-=C2;
    BankAccount::MonthlyProc();
    
    cout<<"Your charge is: "<<C2<<endl;
    
};

#endif /* CheckingAcct_h */
