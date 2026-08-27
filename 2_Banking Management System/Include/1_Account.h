#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Account{
    protected:
        int accountNumber;
        string customerName;
        double balance;
    public:
        Account(int accNum, string name, double bal);
        virtual ~Account(){}
        //Getters
        const int getAccountNumber();
        const string getCustomerName();
        const double getBalance();

        //Banking Function
        virtual void deposit(double amount);
        virtual void withdraw(double amount);
        const virtual void display();
        const virtual string getAccountType() = 0;
        void setBalance(double balance);
};
// Saving Account 
class SavingAccount : public Account{
    private:
        double interestRate;
    public:
        SavingAccount(int accNum, string name, double bal, double rate);
        const void display() override;
        const string getAccountType() override;
};
//Current Account 
class CurrentAccount : public Account{
    private:
        double overdraftLimit;
    public:
        CurrentAccount(int accNum, string name, double bal, double limit);

        void withdraw(double amount) override;
        const void display() override;
        const string getAccountType() override;   
};

#endif