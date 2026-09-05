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

      void Add_Vehicle();
      void Display_Vehicle() const;

      void Rent_Vehicle();
      void Return_Vehicle(); 
};
#endif // !RENTALSYSTEM_H
