#include <iostream>
#include "../Header/Bill.h"
using namespace std;

int main() {
   vector<MenuItem> menuList;
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

   Bill myBill(menuList);
   myBill.get_bill();
   return 0;
}