#include "helpers.h"
#include <algorithm>

// Define highestMileage function
Vehicle highestMileage(Vehicle* arr, int size) {
    int highestIdx = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i].mileage > arr[highestIdx].mileage) {
            highestIdx = i;
        }
    }
    return arr[highestIdx];
}

// Define inventoryValue function
float inventoryValue(Vehicle* arr, int size) {
    float totalValue = 0;
    for (int i = 0; i < size; i++) {
        totalValue += arr[i].cost;
    }
    return totalValue;
}

// Define sortInventory function
unique_ptr<Vehicle[]> sortInventory(Vehicle* arr, int size) {
    unique_ptr<Vehicle[]> sortedArr(new Vehicle[size]);
    for (int i = 0; i < size; i++) {
        sortedArr[i] = arr[i];
    }
    sort(sortedArr.get(), sortedArr.get() + size, [](const Vehicle &a, const Vehicle &b) {
        if (a.make != b.make) return a.make < b.make;
        if (a.model != b.model) return a.model < b.model;
        if (a.year != b.year) return a.year < b.year;
        if (a.cost != b.cost) return a.cost < b.cost;
        return a.mileage < b.mileage;
    });
    return sortedArr;
}

// Updated mergeInventory function
unique_ptr<Vehicle[]> mergeInventory(Vehicle* arr1, int size1, Vehicle* arr2, int size2) {
    int totalSize = size1 + size2;
    unique_ptr<Vehicle[]> mergedArr(new Vehicle[totalSize]);
    int i = 0, j = 0, k = 0;

    // Copy both arrays into the mergedArr
    while (i < size1) {
        mergedArr[k++] = arr1[i++];
    }
    while (j < size2) {
        mergedArr[k++] = arr2[j++];
    }

    // Sort the merged array
    sort(mergedArr.get(), mergedArr.get() + totalSize, [](const Vehicle &a, const Vehicle &b) {
        if (a.make != b.make) return a.make < b.make;
        if (a.model != b.model) return a.model < b.model;
        if (a.year != b.year) return a.year < b.year;
        if (a.cost != b.cost) return a.cost < b.cost;
        return a.mileage < b.mileage;
    });

    return mergedArr;
}

// Define filterInventory function
vector<Vehicle> filterInventory(Vehicle* arr, int size, int minYear, int maxYear, float maxCost, int maxMileage) {
    vector<Vehicle> filteredVehicles;
    for (int i = 0; i < size; i++) {
        if (arr[i].year >= minYear && arr[i].year <= maxYear &&
            arr[i].cost <= maxCost && arr[i].mileage <= maxMileage) {
            filteredVehicles.push_back(arr[i]);
        }
    }
    return filteredVehicles;
}
