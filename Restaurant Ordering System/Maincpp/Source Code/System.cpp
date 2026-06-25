// #include "../Header/System.h"
// #include <iostream>
// //using namespace std;
// void System::addCustomer(){
//     std::string name;
//     std::cout <<"Customer name: "; std::cin.ignore(); std::getline(std::cin, name);
//     customer.push(name);
//     std::cout <<"Customer added."<<std::endl;
// }
// void System::addTakeOrder(){
//     if(customer.empty()){
//         std::cout <<"No Customer Waiting."<<std::endl;
//         return;
//     }
//     menu.displayMenu();
//     int type;
//     int id;
//     std::cout <<"1. Food "<<std::endl;
//     std::cout <<"2. Drink "<<std::endl;
//     std::cout << "Choose Category (1) or (2): ";
//     std::cin >> type;
//     std::cout << "Item ID: ";
//     std::cin >> id;
//     std::string category;

//     if(type==1)
//         category="Food";
//     else
//         category="Drink";
//     MenuItem* Menu = menu.finditem(id, category);
//     if(Menu)
//     {
//         bill.addOrder(*Menu);

//         std::cout << Menu->name
//              << " added.\n";
//     }
//     else
//     {
//         std::cout << "Invalid item.\n";
//     }
// }
// void System::processCustomer()
// {
//     if(customer.empty())
//     {
//         std::cout << "No customer.\n";
//         return;
//     }

//     std::cout << "\nServing "
//          << customer.front()
//          << std::endl;

//     bill.showBill();

//     customer.pop();
// }

// void System::run()
// {
//     int choice;

//     do
//     {
//         std::cout << "\n===================\n";
//         std::cout << "Restaurant System\n";
//         std::cout << "===================\n";

//         std::cout << "1. Display Menu\n";
//         std::cout << "2. Add Customer\n";
//         std::cout << "3. Take Order\n";
//         std::cout << "4. Cancel Last Order\n";
//         std::cout << "5. Show Bill\n";
//         std::cout << "6. Process Customer\n";
//         std::cout << "0. Exit\n";

//         std::cout << "Choice: ";
//         std::cin >> choice;

//         switch(choice)
//         {
//         case 1:
//             menu.displayMenu();
//             break;

//         case 2:
//             addCustomer();
//             break;

//         case 3:
//             addTakeOrder();
//             break;

//         case 4:
//             bill.cancelLastOrder();
//             break;

//         case 5:
//             bill.showBill();
//             break;

//         case 6:
//             processCustomer();
//             break;
//         }

//     }while(choice!=0);
// }