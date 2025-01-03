#include "helpers.h"

// include source code for functions declared in helpers.h below

map<int, Data> load_data(const string &filename) {
    map<int, Data> inventory;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "File not found" << endl;
        return inventory;
    }

    string line;
    string header;
    getline(file, header);

    while (getline(file, line)) {
        stringstream ss(line);
        Data diamond;
        int inventoryNumber;
        string temp;

        getline(ss, temp, ',');
        inventoryNumber = stoi(temp);
        getline(ss, temp, ',');
        diamond.carat = stod(temp);
        getline(ss, temp, ',');
        diamond.color = temp[0];
        getline(ss, temp, ',');
        diamond.clarity = temp;
        getline(ss, temp, ',');
        diamond.depth = stod(temp);
        getline(ss, temp, ',');
        diamond.table = stod(temp);
        getline(ss, temp, ',');
        diamond.price = stod(temp);
        getline(ss, temp, ',');
        diamond.x = stod(temp);
        getline(ss, temp, ',');
        diamond.y = stod(temp);
        getline(ss, temp, ',');
        diamond.z = stod(temp);

        inventory[inventoryNumber] = diamond;

    }
    file.close();
    return inventory;
}

set<double> unique_carats(const map<int, Data> &inventory) {
    set<double> uniqueCarats;
    for (const auto &item : inventory) {
        uniqueCarats.insert(item.second.carat);
    }
    return uniqueCarats;
}

map<int, Data> select_inventory(const map<int, Data> &inventory, double carat) {
    map<int, Data> selectedInventory;
    for (const auto &item : inventory) {
        if (item.second.carat == carat) {
            selectedInventory[item.first] = item.second;
        }
    }
    return selectedInventory;
}

map<int, Data> certain_size(const map<int, Data> &inventory, double minX, double maxX, double minY, double maxY, double minZ, double maxZ) {
    map<int, Data> result;
    for (const auto &item : inventory) {
        const Data &diamond = item.second;
        if (diamond.x >= minX && diamond.x <= maxX &&
            diamond.y >= minY && diamond.y <= maxY &&
            diamond.z >= minZ && diamond.z <= maxZ) {
            result[item.first] = diamond;
            }
    }
    return result;
}

double price_of_largest(const map<int, Data> &inventory) {
    double maxCarat = 0.0;
    for (const auto &item : inventory) {
        if (item.second.carat > maxCarat) {
            maxCarat = item.second.carat;
        }
    }

    double total = 0.0;
    int count = 0;
    for (const auto &item : inventory) {
        if (item.second.carat == maxCarat) {
            total += item.second.price;
            count++;
        }
    }

    return (count > 0) ? (total / count) : 0.0;
}

tuple<string, Data> sold(const string &customerName, int inventoryNumber, map<int, Data> &inventory) {
    if (inventory.find(inventoryNumber) != inventory.end()) {
        Data soldDiamond = inventory[inventoryNumber];
        inventory.erase(inventoryNumber);
        return make_tuple(customerName, soldDiamond);
    }
    return make_tuple(customerName, Data());
}
