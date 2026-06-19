#ifndef MENUITEM_H
#define MENUITEM_H

#include<iostream>
#include<iomanip>
#include<list>
#include<string>

struct MenuItem{
    int id;
    std::string name;
    double usdPrice;
    int khPrice;
    std::string category;
};
class Menu{

    private:
    std::list<MenuItem> menuList;
    
    public:
    Menu();
    void displayMenu();
    MenuItem*finditem(int id, std::string category);
    
};
#endif
