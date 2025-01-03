#include <iostream>
#include <string>
#include <map>
#include <set>
#include <tuple>
using namespace std;

#include "helpers.h"

int main() {
    // load data from file (update path below after pulling code)
    map<int, Data> all_data = load_data("/home/diamonds_student.csv");

    // print the total number of unique carats in the dataset
    set<double> unique_carats_inv = unique_carats(all_data);
    cout << "Total unique carats: " << unique_carats_inv.size() << endl;

    // print the total number of diamonds that correspond to 0.23 carats
    const double desired_carat_size= 10;
    map<int, Data> matching_carats = select_inventory(all_data, desired_carat_size);
    cout << "Total diamonds with " << desired_carat_size << " carats: " << matching_carats.size() << endl;

    // find all items in inventory within a specific size
    map<int, Data> sized_diamonds = certain_size(all_data, 3, 4, 3, 4, 2, 2.5);
    cout << "The inventory contains " << sized_diamonds.size() << " diamonds that match the desired size" << endl;

    // price of highest
    double price = price_of_largest(all_data);
    cout << "The average cost of the largest-carat diamond is $" << price << endl;

    // sale record
    int sold_inv_number = 5;
    tuple<string, Data> sale_record = sold("Amanda", sold_inv_number, all_data);
    // print to see if data map updated
    if (all_data.count(sold_inv_number)) {
        cout << "Item " << sold_inv_number << " not removed from inventory" << endl;
    }
    else {
        cout << "Item " << sold_inv_number << " successfully removed from inventory" << endl;
    }

}
