#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
   private:
      std::string customer_id;
      std::string name;
      std::string phone_number;

   public:
      ~Customer() {}

      std::string get_customer_id() const { return this->customer_id; }
      std::string get_name() const { return this->name; }
      std::string get_phone_number() const { return this->phone_number; }


      void set_customer_id(const std::string& new_customer_id) {
         this->customer_id = new_customer_id;
      }
      void set_name(const std::string& new_name) {
         this->name = new_name;
      }
      void set_phone_number(const std::string& new_phone_number) {
         this->phone_number = new_phone_number;
      }
};
#endif // CUSTOMER_H
