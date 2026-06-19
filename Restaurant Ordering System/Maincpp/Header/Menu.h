#ifndef MENU_H
#define MENU_H

#include<iostream>
#include<iomanip>
#include<list>
#include<string>
#include "MenuItem.h"
class Menu{

    private:
    std::list<MenuItem> menuList;
    
    public:
    Menu();
    void displayMenu();
    MenuItem*finditem(int id, std::string category);
    
};
#endif
