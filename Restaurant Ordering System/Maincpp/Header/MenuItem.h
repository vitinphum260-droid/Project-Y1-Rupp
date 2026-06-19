#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>

struct MenuItem {
    int id;
    std::string name;
    double usdPrice;
    int khPrice;
    std::string category;
};

#endif
