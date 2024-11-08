#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <cmath>
using namespace std;

// define Vehicle struct below
struct Vehicle{
    string make;
    string model;
    int year;
    float cost;
    int mileage;

    bool underWarranty(int currentYear);
    float monthlyPayment(int nYears, double downPayment, float interest);
};

#endif // DO NOT ADD CODE AFTER THIS LINE
