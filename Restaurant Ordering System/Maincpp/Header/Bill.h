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
    // $1 = 4000៛
    double USD_TO_KHR = 4000.0;
    std::string get_date() {
        std::time_t now = std::time(nullptr);
        std::tm* local_time = std::localtime(&now);
        std::stringstream ss;
        ss << std::put_time(local_time, "%Y-%m-%d %H:%M:%S");
        return ss.str();
    }
    void apply_food_and_drink(std::vector<MenuItem>& list, const MenuItem& item) {
        list.push_back(item);
    }
    void display_item(const std::vector<MenuItem>& menu) {
        if (menu.empty()) {
            std::cout << "              ----- None -----\n";
            return;
        }
        int i = 1;
            std::cout << std::left<< std::setw(5) << "No."<< std::setw(30) << "Item"
                      << std::setw(12) << "USD"<< "KHR\n";
    std::cout << "------------------------------------------------------------\n";
        for (const auto& item : menu) {
            std::cout << std::left<< std::setw(5) << i<< std::setw(30) << item.name
                      << "$" << std::setw(11)
                      << std::fixed << std::setprecision(2)<< item.usdPrice
                      << "៛" << item.khPrice<< "\n";
                    i++;
        }
    }
    double total_usd_price(const std::vector<MenuItem>& menu) {
        double sum = 0;
        for (const auto& item : menu) {
            sum += item.usdPrice;
        }
        return sum;
    }
    unsigned long total_kh_price(const std::vector<MenuItem>& menu) {
        unsigned long sum = 0;
        for (const auto& item : menu) {
            sum += item.khPrice;
        }
        return sum;
    }
    double get_total_usd() {
        return total_usd_price(foods) + total_usd_price(drinks);
    }
    unsigned long get_total_khr() {
        return total_kh_price(foods) + total_kh_price(drinks);
    }
    void total_price_output() {
        double total_usd = get_total_usd();
        unsigned long total_khr = get_total_khr();
        std::cout << "\n";
        std::cout << "============================================================\n";
        std::cout << std::left<< std::setw(35) << "TOTAL"
                  << "$" << std::fixed << std::setprecision(2)<< total_usd
                  << "   =   "<< total_khr << "៛\n";
        std::cout << "============================================================\n";
    }
    void process_payment() {
        double total_usd = get_total_usd();
        unsigned long total_khr = get_total_khr();
        int choice;
        std::cout << "\n";
        std::cout << "==================== PAYMENT ====================\n";
        std::cout << "1. Pay in USD ($)\n";
        std::cout << "2. Pay in Khmer Riel (៛)\n";
        std::cout << "Choose payment currency: ";
        std::cin >> choice;
        if (choice == 1) {
            double paid_usd;
            while (true) {
                std::cout << "\nTotal to pay : $"<< std::fixed 
                          << std::setprecision(2)<< total_usd << "\n";
                std::cout << "Enter amount paid ($): ";
                std::cin >> paid_usd;
                if (paid_usd < total_usd) {
                    std::cout << "\nPayment is not enough!\n";
                    std::cout << "You still need: $"<< std::fixed << std::setprecision(2)
                              << total_usd - paid_usd<< "\n";
                } else {
                    double change = paid_usd - total_usd;
                    std::cout << "\n";
                    std::cout << "---------------- PAYMENT RECEIPT ----------------\n";
                    std::cout << std::left<< std::setw(25)<< "Total"<< "$"<< std::fixed
                              << std::setprecision(2)<< total_usd<< "\n";
                    std::cout << std::setw(25)<< "Amount Paid"<< "$"<< paid_usd<< "\n";
                    std::cout << std::setw(25)<< "Change"<< "$"<< change<< "\n";
                    std::cout << "--------------------------------------------------\n";

                    // Also show change in Khmer Riel
                    std::cout << "Change in Khmer Riel: "
                              << static_cast<unsigned long>(change * USD_TO_KHR)<< "៛\n";
                    std::cout << "--------------------------------------------------\n";
                    break;
                }
            }
        } else if (choice == 2) {
            unsigned long long paid_khr;
            while (true) {
                std::cout << "\nTotal to pay : "<< total_khr << "៛\n";
                std::cout << "Enter amount paid (៛): ";
                std::cin >> paid_khr;
                if (paid_khr < total_khr) {
                    std::cout << "\nPayment is not enough!\n";
                    std::cout << "You still need: "<< total_khr - paid_khr<< "៛\n";
                } else {
                    unsigned long long change = paid_khr - total_khr;
                    std::cout << "\n";
                    std::cout << "---------------- PAYMENT RECEIPT ----------------\n";
                    std::cout << std::left<< std::setw(25)<< "Total"<< total_khr<< "៛\n";
                    std::cout << std::setw(25)<< "Amount Paid"<< paid_khr<< "៛\n";
                    std::cout << std::setw(25)<< "Change"<< change<< "៛\n";
                    std::cout << "--------------------------------------------------\n";
                    
                    // change in USD
                    std::cout << "Change in USD: $"<< std::fixed<< std::setprecision(2)
                              << change / USD_TO_KHR<< "\n";
                    std::cout << "--------------------------------------------------\n";
                    break;
                }
            }
        } else {
            std::cout << "\nInvalid payment option!\n";
        }
    }
public:
    Bill() {}
    Bill(std::vector<MenuItem>& fnd) {
        for (const auto& item : fnd) {
            if (item.category == "Food") {
                apply_food_and_drink(foods, item);
            }
            else if (item.category == "Drink") {
                apply_food_and_drink(drinks, item);
            }
        }
    }
    void addOrder(const MenuItem& item) {
        if (item.category == "Food") {
            apply_food_and_drink(foods, item);
        }
        else if (item.category == "Drink") {
            apply_food_and_drink(drinks, item);
        }
    }
    void cancelLastOrder() {

        if (!foods.empty()) {
            foods.pop_back();
            std::cout << "Last food order cancelled.\n";
        }
        else if (!drinks.empty()) {
            drinks.pop_back();
            std::cout << "Last drink order cancelled.\n";
            }
        else {
            std::cout << "No orders to cancel.\n";
        }
    }
    void showBill() {
        get_bill();
    }
    void get_bill() {
        std::cout << "\n";
        std::cout << "====================CUSTOMER BILL===================\n";
        std::cout << "Date: " << get_date() << "\n";

        std::cout << "\n========================== FOODS ===========================\n";
        display_item(foods);

        std::cout << "\n========================= DRINKS ============================\n";
        display_item(drinks);
        total_price_output();

        // Ask customer to pay
        process_payment();
        std::cout << "\n";
        std::cout << "==================THANK YOU FOR YOUR ORDER!==================\n";
    }
};
#endif