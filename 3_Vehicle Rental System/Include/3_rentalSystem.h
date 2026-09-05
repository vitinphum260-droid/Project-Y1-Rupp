#ifndef RENTALSYSTEM_H
#define RENTALSYSTEM_H

#include <string>
#include <vector>
#include "2_customer.h"
#include "1_vehicle.h"

class Rental {
   private:
      std::vector<Customer> customers;
      std::vector<Vehicle> vehicles;

   public:
      void Add_Customer();
      void Display_Customer() const;

      void addVehicle();
      void showVehicles() const;

      void rentVehicle();
      void returnVehicle();
};
#endif // !RENTALSYSTEM_H
