#include <iostream>
#include "../Include/3_rentalSystem.h"

using namespace std;

int main()
{
    Rental rentalSystem;
    int choice;

    do
    {
        cout << "\n=========================================\n";
        cout << "      VEHICLE RENTAL SYSTEM\n";
        cout << "=========================================\n";
        cout << "1. Add Vehicle\n";
        cout << "2. Show All Vehicles\n";
        cout << "3. Add Customer\n";
        cout << "4. Rent Vehicle\n";
        cout << "5. Return Vehicle\n";
        cout << "6. Print Rental Bill\n";
        cout << "0. Exit\n";
        cout << "=========================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        // case 1:
        //     rentalSystem.addVehicle();
        //     break;

        // case 2:
        //     rentalSystem.showVehicles();
        //     break;

        // case 3:
        //     rentalSystem.Add_Customer();
        //     break;

        // case 4:
        //     rentalSystem.rentVehicle();
        //     break;

        // case 5:
        //     rentalSystem.returnVehicle();
        //     break;

        // case 6:
        //     rentalSystem.printBill();
            break;

        case 0:
            cout << "\nThank you for using the Vehicle Rental System!\n";
            break;

        default:
            cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}