#ifndef SYSTEM_H
#define SYSTEM_H
#include <queue>
#include <limits>
#include "Menu.h"
#include "Bill.h"
class System{
    private:
    Menu menu;
    Bill bill;
    std::queue<std::string> customer;
    public:
    void addCustomer(){
    std::string name;
    std::cout <<"Customer name: "; std::cin.ignore(); std::getline(std::cin, name);
    customer.push(name);
    std::cout <<"Customer added."<<std::endl;
    }
    void addTakeOrder(){
        if(customer.empty()){
            std::cout <<"No Customer Waiting."<<std::endl;
            return;
        }
        menu.displayMenu();
        std::cout << "\nTaking order for " << customer.front() << ".\n";
        // This lets one visit to option 3 contain any number of menu items.
        while (true) {
            int type;
            int id;
            int quantity;
            std::cout << "\n1. Food\n";
            std::cout << "2. Drink\n";
            std::cout << "0. Finish order\n";
            std::cout << "Choose category: ";
            if (!(std::cin >> type)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Please enter a number.\n";
                continue;
            }
            if (type == 0) {
                std::cout << "Order saved.\n";
                break;
            }
            if (type != 1 && type != 2) {
                std::cout << "Invalid category.\n";
                continue;
            }
            std::cout << "Item ID: ";
            if (!(std::cin >> id)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Please enter a valid item ID.\n";
                continue;
            }
            std::cout << "Quantity: ";
            if (!(std::cin >> quantity) || quantity <= 0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Quantity must be a positive number.\n";
                continue;
            }
            const std::string category = (type == 1) ? "Food" : "Drink";
            MenuItem* selectedItem = menu.finditem(id, category);
            if (!selectedItem) {
                std::cout << "Invalid item.\n";
                continue;
            }
            for (int i = 0; i < quantity; ++i) {
                bill.addOrder(*selectedItem);
            }
            std::cout << quantity << " x " << selectedItem->name << " added.\n";
        }
    }
    void processCustomer()
    {
        if(customer.empty())
        {
            std::cout << "No customer.\n";
            return;
        }

        std::cout << "\nServing "
            << customer.front()<< std::endl;

        bill.showBill();

        customer.pop();
    }
    void run()
    {
        int choice;
        do
        {
            std::cout << "\n";
            std::cout << "=================== Welcome to our restuarant ===================\n";
            std::cout << "\n";
            std::cout << "1. Add Customer\n";
            std::cout << "2. Display Menu\n";
            std::cout << "3. Take Order\n";
            std::cout << "4. Show Bill\n";
            std::cout << "0. Exit\n";
            std::cout << "\n";
            std::cout << "Choice: ";
            std::cin >> choice;
            switch(choice)
            {
            case 1:
                addCustomer();
                break;
                
            case 2:
                menu.displayMenu();
                break;

            case 3:
                addTakeOrder();
                break;
            case 4:
                bill.showBill();
                break;
            }

        }while(choice!=0);
    }
};
#endif