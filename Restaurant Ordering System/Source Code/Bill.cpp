#include <iostream>
#include "../Include/Bill.h"
using namespace std;

int main() {
   print_Date();
   cout << "Wait for another date:" << endl;
   wait_for(3);
   print_Date();
   return 0;
}