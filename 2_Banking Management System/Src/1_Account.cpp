#include "../Include/1_Account.h"
using namespace std;

// Account Constructor
Account::Account(int accNum, string name, double bal){
    accountNumber = accNum;
    customerName = name;
    balance = bal;
}
// Getter
const int Account::getAccountNumber(){
    return accountNumber;
}
const string Account::getCustomerName(){
    return customerName;
}
const double Account::getBalance(){
    return balance;
}
// Deposit 
void Account::deposit(double amount){
    if(amount<=0){
        throw invalid_argument("Deposit amount must be greater than zero.");
    }
    balance += amount;
    cout <<"\nDeposit Successful.\n";
}
// Withdraw
void Account::withdraw(double amount){
    if(amount<=0){
        throw invalid_argument("Withdraw amount must be greater than zero.");
    }
    else if(amount > balance){
        throw runtime_error("Insufficient Balance.");
    }
    balance -= amount;
    cout <<"\nwithdraw Successfull.\n";
}
// Display
const void Account::display(){
    cout <<"\n===============================\n";
    cout <<"Account Number : "<< accountNumber <<endl;
    cout <<"Customer Name  : "<< customerName <<endl;
    cout <<"Account Type   : "<< getAccountType() <<endl;
    cout <<"Balance        : $"<< balance <<endl;
    cout <<"\n================================\n";
}
//
void Account::setBalance(double balance){
    this->balance = balance;
}
// Saving Account 
SavingAccount::SavingAccount(int accNum, string name, double bal, double rate)
:Account(accNum, name, bal){
    interestRate = rate;
}
const string SavingAccount::getAccountType(){
    return "Saving";
}
const void SavingAccount::display(){
    Account::display();
    cout <<"Interest Rate : "<< interestRate <<"%\n";
} 
// Current Account
CurrentAccount::CurrentAccount(int accNum, string name, double bal, double limit)
:Account(accNum, name, bal){
    overdraftLimit = limit;
}
const string CurrentAccount::getAccountType(){
    return "Current";
}
void CurrentAccount::withdraw(double amount){
    if(amount <= 0){
        throw invalid_argument("withdraw amount must be greater than zero.");
    }
    else if(balance - amount < -overdraftLimit){
        throw runtime_error("Overdraft limit exceeded.");
    }
    balance -= amount;
    cout <<"\nWithdraw Successful.\n";
}
const void CurrentAccount::display(){
    Account::display();
    cout <<"Overdraft Limit : $"<< overdraftLimit <<endl;
    
}
