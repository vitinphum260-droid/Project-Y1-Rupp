#include"../Header/Menu.h"
#ifdef _WIN32
#include <windows.h>
#endif

Menu::Menu(){
#ifdef _WIN32
   SetConsoleOutputCP(CP_UTF8);
   SetConsoleCP(CP_UTF8);
#endif
    //Food
    menuList.push_back({1,"Fried Rice: ",2.50,10000,"Food"});
    menuList.push_back({2,"Chicken Noodle Soup: ",2,8000,"Food"});
    menuList.push_back({3,"Beef Lok Lak Rice: ",3.25,13000,"Food"});
    menuList.push_back({4,"Grilled Pork Rice:" ,2.50,10000,"Food"});
    menuList.push_back({5,"Khmer Curry: ",2.75,11000,"Food"});

    //Drink
    menuList.push_back({1,"Pepsi: ",1,4000,"Drink"});
    menuList.push_back({2,"Cocacola: ",1.25,5000,"Drink"});
    menuList.push_back({3,"Fresh Orange Juice: ",1.75,7000,"Drink"});
    menuList.push_back({4,"Hot tea: ",1.25,5000,"Drink"});
    menuList.push_back({5,"Beer: ",3.00,12000,"Drink"});
}

void Menu::displayMenu(){
    std::cout<<"\n========== Food ==========\n";
        for(auto item:menuList){
            if(item.category == "Food"){
                std::cout<<item.id
                            <<","
                            <<item.name
                            <<":$"
                            << std::fixed << std::setprecision(2)
                            << item.usdPrice
                            << " = "
                            << item.khPrice
                            << ": \u17DB";
            }
        }
    std::cout<<"\n========== Drink ==========\n";
        for(auto item:menuList){
            if(item.category == "Drink"){
                std::cout<<item.id
                            <<","
                            <<item.name
                            <<":$"
                            <<std::fixed << std::setprecision(2)
                            <<item.usdPrice
                            <<" = "
                            <<item.khPrice
                            <<": \u17DB";
            }
        }
}

MenuItem* Menu::finditem(int id, std::string category){
    for(auto & item:menuList){
        if(item.id == id && item.category == category){
            return &item;
        }
    }

    return nullptr;
}
