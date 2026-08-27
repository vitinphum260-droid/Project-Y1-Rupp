#ifndef BANKSYSTEM_H
#define BANKSYSTEM_H

#include <iostream>
#include <unordered_map>
#include <stack>
#include <queue>
#include <vector>
#include <string>

#include "../Include/1_Account.h"
#include "../Include/2_Transaction.h"

using namespace std;
class BankSystem{
    private:
        //Data Structures
        //Hash Table
        unordered_map<int, Account*> accounts;
        //Undo Transaction
        queue<Transaction> pendingQueue;
        //Stack for undo
        stack<Transaction> undoStack;
        //Complete Transaction History
        vector<Transaction> transactionHistory;
        //Auto Generate Account Number
        int nextAccountNumber;

    public:
        //Constructor / Destructure
        
        BankSystem();
        ~BankSystem();
        //Account Management
        void createSavingAccount(string customerName, double balance, double interestRate);
        void createCurrentAccount( string customerName, double balance, double overdraftLimit);
        
        void deleteAccount(int accountNumber);
        Account* searchAccount(int accountNumber);
        bool accountExists(int accountNumber);
        const void displayAllAccounts();
        
        //Banking Operations
        void deposit(int accountNumber, double amount);
        void withdraw(int accountNumber, double amount);
        void transfer(int fromAccount, int toAccount, double amount);

        //Transaction Management
        void undoTransaction();
        void processPendingTransactions();
        void displayTransactionHistory();

        //Reports
        const int getTotalAccount();
        const double getTotalMoney();

        //Utility
        int generateAccountNumber();
        
};
#endif