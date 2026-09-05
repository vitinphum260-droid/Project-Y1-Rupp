#include <iostream>
#include "../Include/3_rentalSystem.h"
using namespace std;

void Rental::Add_Customer() {
   Customer cus;
   string id, name, phone;

   cin.ignore();
   cout << "Enter Customer ID           : "; getline(cin, id);
   cout << "Enter Customer Name         : "; getline(cin, name);
   cout << "Enter Customer Phone Number : "; getline(cin, phone);
   cus.set_customer_id(id);
   cus.set_name(name);
   cus.set_phone_number(phone);

   customers.push_back(cus);
   cout << "New Customer Added." << endl;
}

void Rental::Display_Customer() const {
   cout << "=====> Customer Lists <=====" << endl;
   for (const auto& cus : customers) {
      cout << "ID: " << cus.get_customer_id();
      cout << "| Name: " << cus.get_name();
      cout << "| Phone: " << cus.get_phone_number() << endl;
   }
}

void Rental::addVehicle() {
   Vehicle v;
   v.inputVehicle();
   vehicles.push_back(v);
}

void Rental::showVehicles() const {
   if (vehicles.empty()) {
      cout << "No vehicles registered yet." << endl;
      return;
   }
   for (const auto& v : vehicles) {
      v.displayVehicle();
   }
}

void Rental::rentVehicle() {
    int vID;
    std::cout << "\nEnter Vehicle ID to rent: ";
    std::cin >> vID;

    for (auto& v : vehicles) {
        if (v.getVehicleID() == vID) {
            if (!v.isAvailable()) {
                std::cout << "Vehicle is already rented!\n";
                return;
            }
            v.setAvailable(false);
            std::cout << "Vehicle " << vID << " rented successfully!\n";
            return;
        }
    }
    std::cout << "Vehicle ID not found.\n";
}

void Rental::returnVehicle() {
    int vID;
    std::cout << "\nEnter Vehicle ID to return: ";
    std::cin >> vID;

    for (auto& v : vehicles) {
        if (v.getVehicleID() == vID) {
            if (v.isAvailable()) {
                std::cout << "Vehicle was not rented.\n";
                return;
            }
            v.setAvailable(true);
            std::cout << "Vehicle " << vID << " returned successfully!\n";
            return;
        }
    }
    std::cout << "Vehicle ID not found.\n";
}

int main() {
   return 0;
}
