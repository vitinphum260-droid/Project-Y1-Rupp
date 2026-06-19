#ifndef BILL_H
#define BILL_H

#include <iostream>
#include <ctime>
#include <thread> 
#include <chrono> 

inline void wait_for(unsigned int second) {
   std::this_thread::sleep_for(std::chrono::seconds(second));
}

inline void print_Date() {
   std::time_t now = std::time(0);
   std::tm* date = std::localtime(&now);

   std::cout << "Date: " << date->tm_mday << "/" << date->tm_mon + 1 << "/" << date->tm_year + 1900 << std::endl;
}

inline void Log(std::string prompt) {
   std::cout << prompt << std::endl;
}

#endif