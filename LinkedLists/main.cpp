#include <iostream>
#include "LinkedList.h"

int main() {

    // create an empty linked list
    LinkedList<double> list;

    list.insertNode(8.2);
    list.insertNode(2.5);
    list.insertNode(12.6);
    list.insertNode(7.9);

    // display the list
    cout << "Initial values of linked list after inserting:" << endl;
    list.displayList();

    list.reverse();

    // display the list
    cout << "Linked List after reversal:" << endl;
    list.displayList();

    list.deleteNode(12.6);

    // display the list
    cout << "Linked List after reversal and deletion:" << endl;
    list.displayList();

    list.make_circular();

    cout << "Circular list:" << endl;
    list.displayList();

    list.make_linear();
    cout << "Linear list:" << endl;
    list.displayList();

}
