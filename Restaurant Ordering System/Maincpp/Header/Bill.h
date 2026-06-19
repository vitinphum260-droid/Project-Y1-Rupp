#ifndef BILL_H
#define BILL_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <ctime>
#include "MenuItem.h"

class Bill {
   private: 
      std::vector<MenuItem> drinks;
      std::vector<MenuItem> foods;

      std::string get_date() {
         std::time_t now = std::time(nullptr);
         std::tm* local_time = std::localtime(&now); 

         std::stringstream ss;
         ss << std::put_time(local_time, "%Y-%m-%d %H:%M:%S");
         return ss.str();
      }

      void apply_food_and_drink(std::vector<MenuItem>& fad, const MenuItem& item) {
         fad.push_back(item);
      }

      void display_item(std::vector<MenuItem>& menu) {
         int i = 1;
         for (const auto& item : menu) {
            std::cout << i 
                      << ". " 
                      << std::left   
                      << std::setw(30)  
                      << item.name 
                      << "$ " 
                      << std::left 
                      << std::setw(4) 
                      << std::setprecision(2) 
                      << item.usdPrice 
                      << " : \u17DB" 
                      << item.khPrice 
                      << std::endl;
            i++;
         }
      }

      double total_usd_price(std::vector<MenuItem>& menu) {
         double sum = 0;
         for (auto& item : menu) {
            sum += item.usdPrice;
         }
         return sum;
      }

      unsigned long total_kh_price(std::vector<MenuItem>& menu) {
         unsigned long sum = 0;
         for (auto& item : menu) {
            sum += item.khPrice;
         } return sum;
      }

      void total_price_output() {
         unsigned long total_kh = total_kh_price(foods) + total_kh_price(drinks);
         double total_usd = total_usd_price(foods) + total_usd_price(drinks);
         std::cout << "  " 
                   << std::left 
                   << std::setw(30) 
                   << "Total:" 
                   << "$ " 
                   << std::left 
                   << std::setw(4) 
                   << std::setprecision(2) 
                   << total_usd 
                   << " : \u17DB" 
                   << total_kh << std::endl;
      }
   public: 
   Bill() {}

   Bill(std::vector<MenuItem>& fnd) {
      for (const auto& item : fnd) {
         if (item.category == "Food") {
            apply_food_and_drink(foods, item);
         } else if (item.category == "Drink") {
            apply_food_and_drink(drinks, item);

         }
      }
   }
   void addOrder(const MenuItem& item) {
      if (item.category == "Food") {
         apply_food_and_drink(foods, item);
      } else if (item.category == "Drink") {
         apply_food_and_drink(drinks, item);
      }
   }

   void cancelLastOrder() {
      if (!foods.empty()) {
         foods.pop_back();
         std::cout << "Last food order cancelled.\n";
      } else if (!drinks.empty()) {
         drinks.pop_back();
         std::cout << "Last drink order cancelled.\n";
      } else {
         std::cout << "No orders to cancel.\n";
      }
   }

   void showBill() {
      get_bill();
   }

   void get_bill() {
      std::cout << "Bill : " << get_date() << std::endl;
      std::cout << "======================> Foods <=======================" << std::endl;
      display_item(foods); 
      std::cout << "======================> Drinks <======================" << std::endl;
      display_item(drinks);
      std::cout << "======================> Total <=======================" << std::endl;
      total_price_output();
   }

};

#endif
