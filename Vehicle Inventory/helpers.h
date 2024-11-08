#ifndef HELPERS_H
#define HELPERS_H

#include <memory>
#include "vehicle.h"
#include <iostream>
#include <vector>
using namespace std;

// Function declarations for highestMileage, inventoryValue, sortInventory, mergeInventory, and filterInventory
Vehicle highestMileage(Vehicle* arr, int size);
float inventoryValue(Vehicle* arr, int size);
unique_ptr<Vehicle[]> sortInventory(Vehicle* arr, int size);
unique_ptr<Vehicle[]> mergeInventory(Vehicle* arr1, int size1, Vehicle* arr2, int size2);
vector<Vehicle> filterInventory(Vehicle* arr, int size, int minYear = 0, int maxYear = 2024, float maxCost = 10000000, int maxMileage = 10000000);

#endif // DO NOT ADD CODE AFTER THIS LINE
