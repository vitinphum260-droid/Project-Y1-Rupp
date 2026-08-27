#ifndef TRNASACTION_H
#define TRANSACTION_H
#include <iostream>
#include <string>
using namespace std;

class Transaction {
    private:
        int accountNumber;
        string transactionType;
        double amount;
        double oldBalance;
        double newBalance;
        string dateTime;
    public:
        // Default Constructor
        Transaction();
        // Constructor
        Transaction(int accNum, string type, double amt, double oldBal, double newBal);
        // Getter
        const int getAccountNumber();
        const string getTransactionType();
        const double getAmount();
        const double getOldBalance();
        const double getNewBalance();
        const string getDateTime();

        //Display Transaction 
        void display() const;
    private:
        string getCurrentDateTime();
};
#endif
