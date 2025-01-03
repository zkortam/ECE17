#include "LinkedList.h"
#include <iostream>
#include <stdexcept>
using namespace std;
// define LinkedList methods below

LinkedList::LinkedList() : head(nullptr), size(0) {}

LinkedList::~LinkedList() {
    ListNode* current = head;
    while (current) {
        ListNode* toDelete = current;
        current = current->next;
        delete toDelete;
    }
}

void LinkedList::insert(int month, double price) {
    ListNode* newNode = new ListNode(month, price, head);
    head = newNode;
    size++;
}

void LinkedList::deleteNode(double price) {
    if (!head){
        cout << "Cannot delete from an empty list." << endl;
        return;
    }
    ListNode* current = head;
    ListNode* previous = nullptr;
    while (current && current->price != price) {
        previous = current;
        current = current->next;
    }
    if (!current){
        cerr << "Price " << price << " not found in the list." << endl;
        return;
    }
    if (!previous) {
        head = head->next;
    } else {
        previous->next = current->next;
    }
    delete current;
    size--;
}

double LinkedList::find(int month) const {
    if (!head){
        throw EmptyListException();
    }
    ListNode* current = head;
    while (current) {
        if (current->month == month) {
            return current->price;
        }
        current = current->next;
    }
    throw runtime_error("Month not found.");
}

void LinkedList::displayList() const {
    if (!head){
        return;
    }
    ListNode* current = head;
    while (current) {
        cout << "Month: " << current->month << "\tPrice: " << current->price << endl;
        current = current->next;
    }
}

int LinkedList::getSize() const {
    return size;
}

void LinkedList::bubbleSort() {
    if (!head || !head->next){
        return;
    }

    bool swapped;
    do {
        swapped = false;
        ListNode* current = head;
        while (current->next) {
            if (current->price > current->next->price) {
                swap(current->price, current->next->price);
                swap(current->month, current->next->month);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}


LinkedList LinkedList::averageMonthlyPrice() const {
    LinkedList monthlyAverages;
    for (int m = 1; m <= 12; ++m) {
        double sum = 0.0;
        int count = 0;
        ListNode* current = head;
        while (current) {
            if (current->month == m) {
                sum += current->price;
                count++;
            }
            current = current->next;
        }

        if (count > 0) {
            monthlyAverages.insert(m, sum / count);
        }
    }
    monthlyAverages.bubbleSort();
    return monthlyAverages;
}

double LinkedList::operator[](int index) const {
    if (index < 0) {
        throw NegativeIndex("Attempt to access negative index.");
    }
    if (index >= size) {
        throw LargeIndex("Attempt to access memory outside linked list.");
    }
    ListNode* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->price;
}

void LinkedList::appendNode(int month, double price) {
    ListNode* newNode = new ListNode(month, price);
    if (!head) {
        head = newNode;
    } else {
        ListNode* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
    size++;
}
