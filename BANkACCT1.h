//
//  BANkACCT1.h
//  BANKPROJ
//
//  Created by Hasan Qureshi on 7/31/17.
//  Copyright © 2017 Hasan Qureshi. All rights reserved.
//
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#ifndef BANkACCT1_h
#define BANkACCT1_h
class BankAccount
{
public:
    BankAccount(int ban, string AcctH, double CB, double AnnualIR);//constructor each class will contain these charasteristics.
    void Deposit(double pDep);//parameter deposit
    void Withdraw(double pWit);//function withdrawls
    void CalcInt();//Calculate interest
    void MonthlyProc();//monthly proc
    double CB=0;
    double MonthlyCharge=0;
    int GetNow();
    int GetNod();
private:
    int ban;
    string AcctH;
    int Nod,Now;
    double AnnualIR;
};
BankAccount::BankAccount(int pban, string pAcctH, double pCB, double pAnnualIR)//constuctor
{
    CB=pCB;
    ban=pban;
    AcctH=pAcctH;
    AnnualIR=pAnnualIR;
};
void BankAccount::Deposit(double pDep)
{
    CB+=pDep;//accepting deposits and updating current
    Nod++;//updating number of deposits
}//Parameter deposit.
void BankAccount::Withdraw(double pWit)
{
    CB-=pWit;
    Now++;
}
void BankAccount::CalcInt()//no arguments but updates CB with current interest.
{
    double Mint;
    double MintR;
    
    MintR=(AnnualIR/12);//monthly interest rate
    Mint=MintR*CB;//to get monthly interest
    CB+=Mint;//updates Balence with current interest.
}
void BankAccount::MonthlyProc()
{
    
    CB-=MonthlyCharge;
    CalcInt();
    MonthlyCharge=0;
    Now=0;
    Nod=0;
}
int BankAccount::GetNow()
{
    return Now;
}
int BankAccount::GetNod()
{
    return Nod;
}
#endif /* BANkACCT1_h */
