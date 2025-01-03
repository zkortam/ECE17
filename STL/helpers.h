#ifndef ECE17HW5_HELPERS_H
#define ECE17HW5_HELPERS_H

// declare struct and functions below
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <tuple>
#include <string>
using namespace std;

struct Data {
    double carat;
    char color;
    string clarity;
    double depth;
    double table;
    double price;
    double x, y, z;
};

map<int, Data> load_data(const string &filename);
set<double> unique_carats(const map<int, Data> &inventory);
map<int, Data> select_inventory(const map<int, Data> &inventory, double carat);
map<int, Data> certain_size(const map<int, Data> &inventory, double minX, double maxX, double minY, double maxY, double minZ, double maxZ);
double price_of_largest(const map<int, Data> &inventory);
tuple<string, Data> sold(const string &customerName, int inventoryNumber, map<int, Data> &inventory);

#endif
