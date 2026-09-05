#include <iostream>
#include "../Include/3_rentalSystem.h"

int main()
{
    Rental rentalSystem;
    int choice;

    do
    {
        std::cout << "\n=========================================\n";
        std::cout << "      VEHICLE RENTAL SYSTEM\n";
        std::cout << "=========================================\n";
        std::cout << "1. Add Vehicle\n";
        std::cout << "2. Show All Vehicles\n";
        std::cout << "3. Add Customer\n";
        std::cout << "4. Rent Vehicle\n";
        std::cout << "5. Return Vehicle\n";
        std::cout << "0. Exit\n";
        std::cout << "=========================================\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            rentalSystem.addVehicle();
            break;

        case 2:
            rentalSystem.showVehicles();
            break;

        case 3:
            rentalSystem.Add_Customer();
            break;

        case 4:
            rentalSystem.rentVehicle();
            break;

        case 5:
            rentalSystem.returnVehicle();
            break;

        case 0:
            std::cout << "\nThank you for using the Vehicle Rental System!\n";
            break;

        default:
            std::cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
