#include "../Include/1_vehicle.h"

// =======================
// Constructor
// =======================
Vehicle::Vehicle()
{
    vehicleID = 0;
    type = "";
    model = "";
    ownerName = "";
    pricePerDay = 0.0;
    available = true;
}

// =======================
// Setters
// =======================
void Vehicle::setVehicleID(int id)
{
    vehicleID = id;
}

void Vehicle::setType(string t)
{
    type = t;
}

void Vehicle::setModel(string m)
{
    model = m;
}

void Vehicle::setOwnerName(string owner)
{
    ownerName = owner;
}

void Vehicle::setPricePerDay(double price)
{
    pricePerDay = price;
}

void Vehicle::setAvailable(bool status)
{
    available = status;
}

// =======================
// Getters
// =======================
int Vehicle::getVehicleID() const
{
    return vehicleID;
}

string Vehicle::getType() const
{
    return type;
}

string Vehicle::getModel() const
{
    return model;
}

string Vehicle::getOwnerName() const
{
    return ownerName;
}

double Vehicle::getPricePerDay() const
{
    return pricePerDay;
}

bool Vehicle::isAvailable() const
{
    return available;
}

// =======================
// Input Vehicle
// =======================
void Vehicle::inputVehicle()
{
    cout << "\n========== Add Vehicle ==========\n";

    cout << "Enter Vehicle ID: ";
    cin >> vehicleID;
    cin.ignore();

    cout << "Enter Vehicle Type (Car/Motorcycle): ";
    getline(cin, type);

    cout << "Enter Vehicle Model: ";
    getline(cin, model);

    cout << "Enter Owner Name: ";
    getline(cin, ownerName);

    cout << "Enter Price Per Day ($): ";
    cin >> pricePerDay;

    available = true;

    cout << "\nVehicle added successfully!\n";
}

// =======================
// Display Vehicle
// =======================
void Vehicle::displayVehicle() const
{
    cout << "\n========================================\n";
    cout << "Vehicle ID   : " << vehicleID << endl;
    cout << "Type         : " << type << endl;
    cout << "Model        : " << model << endl;
    cout << "Owner        : " << ownerName << endl;
    cout << "Price / Day  : $" << pricePerDay << endl;
    cout << "Status       : ";

    if (available)
        cout << "Available";
    else
        cout << "Rented";

    cout << endl;
    cout << "========================================\n";
}
