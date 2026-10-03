#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <iomanip>
#include <list>
#include <string>
#include "MenuItem.h"

#ifdef _WIN32
#include <windows.h>
#endif

class Menu {
private:
    std::list<MenuItem> menuList;
public:
    Menu() {
#ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
#endif
        //           FOOD
        menuList.push_back({1, "Fried Rice", 2.50, 10000, "Food"});
        menuList.push_back({2, "Chicken Noodle Soup", 2.00, 8000, "Food"});
        menuList.push_back({3, "Beef Lok Lak Rice", 3.25, 13000, "Food"});
        menuList.push_back({4, "Grilled Pork Rice", 2.50, 10000, "Food"});
        menuList.push_back({5, "Khmer Curry", 2.75, 11000, "Food"});

        //          DRINK
        menuList.push_back({1, "Pepsi", 1.00, 4000, "Drink"});
        menuList.push_back({2, "Coca-Cola", 1.25, 5000, "Drink"});
        menuList.push_back({3, "Fresh Orange Juice", 1.75, 7000, "Drink"});
        menuList.push_back({4, "Hot Tea", 1.25, 5000, "Drink"});
        menuList.push_back({5, "Beer", 3.00, 12000, "Drink"} );
    }
    //DISPLAY FOOD
    void displayFood() {
        std::cout << "\n";
        std::cout << "============================================================\n";
        std::cout << "                         FOOD MENU\n";
        std::cout << std::left<< std::setw(6)  << "ID"<< std::setw(30) << "Food"
                  << std::setw(15) << "USD"<< "KHR\n";
        std::cout << "------------------------------------------------------------\n";
        for (const auto& item : menuList) {
            if (item.category == "Food") {
                std::cout << std::left<< std::setw(6) << item.id
                          << std::setw(30) << item.name<< "$"
                          << std::setw(14)<< std::fixed<< std::setprecision(2)
                          << item.usdPrice<< item.khPrice<< " ៛\n";
            }
        }
    }
    // DISPLAY DRINK
    void displayDrink() {
        std::cout << "============================================================\n";
        std::cout << "                        DRINK MENU\n";
        std::cout << std::left<< std::setw(6)  << "ID"<< std::setw(30) << "Drink"
                  << std::setw(15) << "USD"<< "KHR\n";
        std::cout << "------------------------------------------------------------\n";
        for (const auto& item : menuList) {
            if (item.category == "Drink") {
                std::cout << std::left<< std::setw(6) << item.id<< std::setw(30) << item.name
                          << "$"<< std::setw(14)<< std::fixed<< std::setprecision(2)
                          << item.usdPrice<< item.khPrice<< " ៛\n";
            }
        }
        std::cout << "============================================================\n";
    }

    //                  DISPLAY ALL MENU
    void displayMenu() {
        std::cout << "\n";
        std::cout << "#                    RESTAURANT MENU                       #\n";
        displayFood();
        displayDrink();
        std::cout << "Exchange Rate: $1 = 4,000 ៛\n";
    }
    //                     FIND ITEM
    MenuItem* finditem(int id, std::string category) {
        for (auto& item : menuList) {
            if (item.id == id &&
                item.category == category) {
                return &item;
            }
        }
        return nullptr;
    }
};
#endif