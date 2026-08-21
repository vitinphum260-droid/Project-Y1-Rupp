#ifndef RENTALSYSTEM_H
#define RENTALSYSTEM_H

#include <string>
#include <vector>
#include "2_customer.h"

class Rental {
   private:
      std::vector<Customer> customer;

   public:
      void Add_Customer(const Customer& cus);

      void Display_Customer() const;
};
#endif // !RENTALSYSTEM_H
