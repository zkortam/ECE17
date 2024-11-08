#include <iostream>
#include <memory>
#include "helpers.h"
#include "vehicle.h"
using namespace std;


int main() {

    // declare variables
    const int numItems1 = 3;
    const int numItems2 = 5;

    // inventory arrays
    struct Vehicle inventory1[numItems1];
    struct Vehicle inventory2[numItems2];

    // populate inventory1
    inventory1[0].make = "Toyota"; inventory1[0].model = "Camry"; inventory1[0].year = 2021; inventory1[0].cost = 22197.50; inventory1[0].mileage = 8176;
    inventory1[1].make = "Subaru"; inventory1[1].model = "Legacy"; inventory1[1].year = 2015; inventory1[1].cost = 13455.00; inventory1[1].mileage = 98790;
    inventory1[2].make = "Honda"; inventory1[2].model = "Accord"; inventory1[2].year = 2011; inventory1[2].cost = 12345.89; inventory1[2].mileage = 64532;

    // populate inventory2
    inventory2[0].make = "Ford"; inventory2[0].model = "Mustang"; inventory2[0].year = 2021; inventory2[0].cost = 39500.50; inventory2[0].mileage = 1000;
    inventory2[1].make = "Ford"; inventory2[1].model = "Mustang"; inventory2[1].year = 2021; inventory2[1].cost = 39500.50; inventory2[1].mileage = 500;
    inventory2[2].make = "Ford"; inventory2[2].model = "Mustang"; inventory2[2].year = 2024; inventory2[2].cost = 460000.25; inventory2[2].mileage = 0;
    inventory2[3].make = "Audi"; inventory2[3].model = "A6"; inventory2[3].year = 2024; inventory2[3].cost = 460000.25; inventory2[3].mileage = 0;
    inventory2[4].make = "Audi"; inventory2[4].model = "A5"; inventory2[4].year = 2024; inventory2[4].cost = 460000.25; inventory2[4].mileage = 0;

    // test cases on all Vehicle structs in inventory1
    for (int i = 0; i < numItems1; i++) {
        if (inventory1[i].underWarranty(2024)) {
            cout << "Vehicle " << i+1 << " is under warranty." << endl;
            cout << endl;
        }
        else {
            cout << "Vehicle " << i+1 << " IS NOT under warranty." << endl;
            cout << endl;
        }
    }

    // test case on first Vehicle in inventory1 for monthly payment
    float v1_mp = inventory1[0].monthlyPayment(5, 0, 0.05);
    cout << "The monthly payment for Vehicle 1 is $" << v1_mp << endl;
    cout << endl;

    // test case for highest mileage car in inventory1
    struct Vehicle mostDriven = highestMileage(inventory1, numItems1);
    cout << "The vehicle with the highest mileage is the " << mostDriven.make << " "
         << mostDriven.model << endl;
    cout << endl;

    // test case for total value of inventory1
    float inventory_total_price = inventoryValue(inventory1, numItems1);
    cout << "The total value of the inventory is $" << inventory_total_price << endl;
    cout << endl;

    // test case for sorting on inventory2
    unique_ptr<Vehicle[]> sorted_inventory = sortInventory(inventory2, numItems2);
    cout << "Sorted Vehicles: " << endl;
    std::cout << "Make\t" << "Model\t" << "Year\t" << "Cost\t" << "Mileage" << endl;
    for (int i = 0; i < numItems2; i++) {
        cout << sorted_inventory[i].make << "\t" << sorted_inventory[i].model << "\t" << sorted_inventory[i].year
             << "\t" << sorted_inventory[i].cost << "\t" << sorted_inventory[i].mileage << endl;
    }
    cout << endl;

    // test case for merging inventory1 and inventory2
    unique_ptr<Vehicle[]> merged_inventory = mergeInventory(inventory1, numItems1, inventory2, numItems2);
    cout << "Merged Inventory: " << endl;
    std::cout << "Make\t" << "Model\t" << "Year\t" << "Cost\t" << "Mileage" << endl;
    for (int i = 0; i < (numItems1+numItems2); i++) {
        cout << merged_inventory[i].make << "\t" << merged_inventory[i].model << "\t" << merged_inventory[i].year
             << "\t" << merged_inventory[i].cost << "\t" << merged_inventory[i].mileage << endl;
    }
}
