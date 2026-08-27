#include "..\Include\3_BankSystem.h"
#include <vector>
#include <stdexcept>
using namespace std;
//Constructor
BankSystem::BankSystem(){
    nextAccountNumber = 1001;
}
//Destructor
BankSystem::~BankSystem(){
    for(auto &account : accounts){
        delete account.second;
    }
    accounts.clear();
}
//Generate New Account Number
int BankSystem::generateAccountNumber(){
    return nextAccountNumber;
}
//Check Account Exists
bool BankSystem::accountExists(int accountNumber){
    return accounts.find(accountNumber) != accounts.end();
}
//Search Account 
Account* BankSystem::searchAccount(int accountNumber){
    auto it = accounts.find(accountNumber);
    if(it == accounts.end()){
        throw runtime_error("Account not found.");
    }
    return it->second;
}
//Create Saving Account 
void BankSystem::createSavingAccount( string customerName, double balance, double interestRate)
{
    int accountNumber = generateAccountNumber();
    Account* newAccount = new SavingAccount(accountNumber, customerName, balance, interestRate);
    accounts[accountNumber] = newAccount;

    cout <<"\n=================================\n";
    cout <<"Saving Account Create Successfully.\n";
    cout <<"Acount Number : "<< accountNumber << endl;
    cout <<"Customer Name : "<< customerName << endl;
    cout <<"===================================\n";
}
// Create Current Account 
void BankSystem::createCurrentAccount(string customerName, double balance, double overdraftLimit){
    int accountNumber = generateAccountNumber();
    Account* newAccount = new CurrentAccount(accountNumber, customerName, balance, overdraftLimit);
    accounts[accountNumber] = newAccount;

    cout <<"\n=================================\n";
    cout <<"Current Account Create Successfully.\n";
    cout <<"Acount Number : "<< accountNumber << endl;
    cout <<"Customer Name : "<< customerName << endl;
    cout <<"===================================\n";
}
//Display All Account 
const void BankSystem::displayAllAccounts(){
    if(accounts.empty()){
        cout <<"\nNo Account found.\n";
        return;
    }
    cout <<"\n==================================\n";
    cout <<"            ALL BANK ACCOUNTS\n";
    cout <<"====================================\n";
    for(const auto &account : accounts){
        account.second->display();
    }
} 
//Deposit Money
void BankSystem::deposit(int accountNumber, double amount){
    try{
        //find account 
        Account *account = searchAccount(accountNumber);
        //Save old balance before deposit
        double oldBalance = account->getBalance();
        //Deposit money
        account->deposit(amount);
        //Get new balance
        double newBalance = account->getBalance();
        //Create transaction record
        Transaction transaction(accountNumber, "Deposit", amount, oldBalance, newBalance);
        
        //Push into Stack for Undo
        undoStack.push(transaction);
        //Add into Queue
        pendingQueue.push(transaction);
        //Save complete Transaction History
        transactionHistory.push_back(transaction);
        cout <<"\nTransaction recorded Successfully.\n";
    }
    catch(const exception &e){
        cout <<"\nError: "<<e.what()<<endl;
    }
}
//Withdraw Money
void BankSystem::withdraw(int accountNumber, double amount){
    try{
        //Find the account
        Account *account = searchAccount(accountNumber);
        //Save old balance before withdraw
        double oldBalance = account->getBalance();
        //withdraw money
        account->withdraw(amount);
        //Get new Balance
        double newBalance = account->getBalance();
        //Create transaction record
        Transaction transaction(accountNumber, "Withdraw", amount, oldBalance, newBalance);

        //Push into Stack for Undo
        undoStack.push(transaction);
        //Add into Queue
        pendingQueue.push(transaction);
        //Save Transaction History
        transactionHistory.push_back(transaction);
        cout <<"\nTransaction recorded Successfully.\n";
    }
    catch(const exception &e){
        cout <<"\nError: "<<e.what()<<endl;
    }
}
//Transfer Money
void BankSystem::transfer(int fromAccount, int toAccount, double amount){
    try{
        Account *sender = searchAccount(fromAccount);
        Account *receiver = searchAccount(toAccount);

        double senderOldBalance = sender->getBalance();
        //Withdraw from sender
        sender->withdraw(amount);
        //Deposit to receiver
        receiver->withdraw(amount);
        
        double senderNewBalance = sender->getBalance();
        //Save sender transaction
        Transaction transaction(fromAccount, "Transfer", amount, senderOldBalance, senderNewBalance);

        undoStack.push(transaction);
        pendingQueue.push(transaction);
        transactionHistory.push_back(transaction);

        cout <<"\n===================================\n";
        cout <<"Transfer Successful\n";
        cout <<"From Account : "<< fromAccount <<endl;
        cout <<"To Account   : "<< toAccount <<endl;
        cout <<"Amount       : $ "<< amount <<endl;
        cout <<"\n==================================\n";
    }
    catch(const exception &e){
        cout <<"\nTransfer Failed : "<< e.what() <<endl;
    }
}
//Undo Last Transaction
void BankSystem::undoTransaction(){
    if(undoStack.empty()){
        cout <<"\nNo Transaction to Undo.\n";
        return;
    }
    Transaction transaction = undoStack.top();
    undoStack.pop();

    try{
        Account *account = searchAccount(transaction.getAccountNumber());
        account->setBalance(transaction.getOldBalance());
        cout <<"\n=================================\n";
        cout <<"Last Transaction Undo Successfully.\n";
        cout <<"Account Number : "<< transaction.getAccountNumber() <<endl;
        cout <<"===================================\n";
    }
    catch(const exception &e){
        cout << e.what() <<endl;
    }
}
//Process Pending Transaction
void BankSystem::processPendingTransactions(){
    if(pendingQueue.empty()){
        cout <<"\nNo Pending Transactions.\n";
        return; 
    }
    cout <<"\n==================================\n";
    cout <<"Proccessing Pending Transactio...\n";
    cout <<"==================================\n";
    while(!pendingQueue.empty()){
        Transaction transaction = pendingQueue.front();
        transaction.display();
        pendingQueue.pop();
    }
    cout <<"\nAll Pending Transaction Processed.\n";
}
//Delete Account 
void BankSystem::deleteAccount(int accountNuber){
    auto it = accounts.find(accountNuber);
    if(it == accounts.end()){
        cout <<"\nAccount not found.\n";
        return;
    }
    delete it->second;
    accounts.erase(it);
    cout <<"\n================================\n";
    cout <<"Account Deleted Successfully.\n";
    cout <<"==================================\n";
}
//Display Transaction History
void BankSystem::displayTransactionHistory(){
    if(transactionHistory.empty()){
        cout <<"\nNo Transaction History.\n";
        return;
    }
    cout <<"\n===============================\n";
    cout <<"          TRANSACTION HISTORY\n";
    cout <<"=================================\n";
    for(const Transaction &transaction : transactionHistory){
        transaction.display();
    }
}
//Total Accounts
const int BankSystem::getTotalAccount(){
    return accounts.size();
}
//Total Money in Bank
const double BankSystem::getTotalMoney(){
    double total = 0;
    for(const auto &account : accounts){
        total += account.second->getBalance();
    }
    return total;
}