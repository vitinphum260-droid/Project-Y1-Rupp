#include "../Include/2_Transaction.h"

#include <ctime>
#include <iomanip>
#include <sstream>
using namespace std;

// Default Constructor
Transaction::Transaction(){
    accountNumber = 0;
    transactionType = "";
    amount = 0;
    oldBalance = 0;
    newBalance = 0;
    dateTime = "";
    
}
// Constructor
Transaction::Transaction(int accNum, string type, double amt, double oldBal, double newBal){
    accountNumber = accNum;
    transactionType = type;
    amount = amt;
    oldBalance = oldBal;
    newBalance = newBal;
    dateTime = getCurrentDateTime();

}
// Generate Current Date & Time
string Transaction::getCurrentDateTime(){
    time_t now = time(0);
    tm*ltm = localtime(&now);
    stringstream ss;

    ss << (1900 + ltm->tm_year) << "-"
       << setw(2) << setfill('0') << (1 + ltm->tm_mon) << "-"
       << setw(2) << setfill('0') << ltm->tm_mday << " "
       << setw(2) << setfill('0') << ltm->tm_hour << ":"
       << setw(2) << setfill('0') << ltm->tm_min << ":"
       << setw(2) << setfill('0') << ltm->tm_sec;
    return ss.str();
}

//Getter 
const int Transaction::getAccountNumber(){
    return accountNumber;
}
const string Transaction::getTransactionType(){
    return transactionType;
}
const double Transaction::getAmount(){
    return amount;
}
const double Transaction::getOldBalance(){
    return oldBalance;
}
const double Transaction::getNewBalance(){
    return newBalance;
}
const string Transaction::getDateTime(){
    return dateTime;
}

// Display
void Transaction::display() const {
    cout <<"\n============================================\n";
    cout <<"Account Number : "<< accountNumber <<endl;
    cout <<"Transaction : "<< transactionType <<endl;
    cout <<"Amount : "<< amount <<endl;
    cout <<"Old Balance : "<< oldBalance <<endl;
    cout <<"New Balance : "<< newBalance <<endl;
    cout <<"Date & Time : "<< dateTime <<endl;
    cout <<"\n============================================\n";
    
}
