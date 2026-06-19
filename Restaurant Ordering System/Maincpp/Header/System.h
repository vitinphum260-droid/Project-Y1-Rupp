#ifndef SYSTEM_H
#define SYSTEM_H
#include <queue>
#include "Menu.h"
#include "Bill.h"
class System{
    private:
    Menu menu;
    Bill bill;
    std::queue<std::string> customer;
    public:
    void addCustomer();
    void addtakeOrder();
    void processCustomer();
    void run();
};

#endif