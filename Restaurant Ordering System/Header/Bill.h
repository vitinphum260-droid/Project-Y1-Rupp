#ifndef BILL_H
#define BILL_H

#include <iostream>
#include <thread>
#include <format>
#include <chrono> 
#include <string>

inline void wait_for(unsigned int second) {
   std::this_thread::sleep_for(std::chrono::seconds(second));
}

inline void print_Date() {
   auto now = std::chrono::system_clock::now();
   auto local_now = std::chrono::current_zone()->to_local(now);
   std::string formatted = std::format("{:%Y-%m-%d %H:%M:%S}", std::chrono::floor<std::chrono::seconds>(local_now));
   std::cout << "Current Datetime: " << formatted << std::endl;
}

inline void Log(std::string prompt) {
   std::cout << prompt << std::endl;
}

#endif