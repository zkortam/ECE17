#include <iostream>
#include "LinkedList.h"
#include "helpers.h"
using namespace std;

int main() {

    // call loadFile function and store into a LinkedList object
    LinkedList data = loadFile("/home/1994_weekly_gas_averages.txt");

    try {
        double price = data[-1];
        cout << price << endl;
    }
    catch(LinkedList::NegativeIndex &e) {
        cerr << "Out of bounds error: " << e.what() << endl;
    }
    catch(LinkedList::LargeIndex &e) {
        cerr << "Out of bounds error: " << e.what() << endl;
    }

    // get size of linked list
    cout << "Original size of linked list is: " << data.getSize() << endl;

    // delete both instances of 1.005 and print new size
    data.deleteNode(1.005);
    data.deleteNode(1.005);
    cout << "Linked list size after deleting two nodes: " << data.getSize() << endl;

    // sort list using bubbleSort and then call displayList to examine results
    data.bubbleSort();
    cout << "Linked list has been sorted and has " << data.getSize() << " nodes." << endl;

    // call averageMonthlyPrice and store in new LinkedList object
    cout << "Linked list containing average per month: " << endl;
    LinkedList average_per_month = data.averageMonthlyPrice();
    average_per_month.displayList();

    // search full data list for 1.15
    double v = 0.9956;
    int pos = searchList(data, v);
    if (pos != -1) {
        cout << "Value " << v << " found at position: " << pos << endl;
    }
    else {
        cout << "Value " << v << " not found." << endl;
    }

}
