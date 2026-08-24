#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
private:
    int vehicleID;
    string type;            // Car or Motorcycle
    string model;
    string ownerName;
    double pricePerDay;
    bool available;

public:
    // Constructor
    Vehicle();

    // Setters
    void setVehicleID(int id);
    void setType(string t);
    void setModel(string m);
    void setOwnerName(string owner);
    void setPricePerDay(double price);
    void setAvailable(bool status);

    // Getters
    int getVehicleID() const;
    string getType() const;
    string getModel() const;
    string getOwnerName() const;
    double getPricePerDay() const;
    bool isAvailable() const;

    // Functions
    void inputVehicle();
    void displayVehicle() const;
};

#endif
