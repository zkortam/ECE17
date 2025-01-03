#include <fstream>
#include <iostream>
#include <sstream>
#include "helpers.h"

// define helpers methods below
LinkedList loadFile(const string& fileName) {
    LinkedList gasPrices;
    ifstream file(fileName);
    if (!file) {
        cout << "Unable to open file." << endl;
        return gasPrices;
    }
    string line;
    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }
        stringstream ss(line);
        int month;
        double price;
        ss >> month >> price;
        if (ss.fail()) {
            continue;
        }
        gasPrices.appendNode(month, price);
    }
    file.close();
    return gasPrices;
}

int searchList(const LinkedList& list, double price) {
    int left = 0;
    int right = list.getSize() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        double midPrice = list[mid];

        if (midPrice == price) {
            return mid;
        } else if (midPrice < price) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

