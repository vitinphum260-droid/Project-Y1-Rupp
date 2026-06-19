#ifndef BILL_H
#define BILL_H

#include <iostream>
#include <ctime>
#include <thread> 
#include <chrono> 
using namespace std;

void wait_for(unsigned int second) {
   this_thread::sleep_for(chrono::seconds(second));
}

void print_Date() {
   time_t now = time(0);
   tm* date = localtime(&now);
   cout << "Date: " << date->tm_mday << "/" << date->tm_mon + 1 << "/" << date->tm_year << endl;
}

void Log(string prompt) {
   cout << prompt << endl;
}
#endif