#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

template <typename T>
class LinkedList {
private:
    // Declare a structure for the list and the list head pointer below
    struct ListNode{
        T value;
        ListNode* next;
        ListNode(T val, ListNode* nxt = nullptr) : value(val), next(nxt) {}
    };
    ListNode* head;

public:
    // *********************************************
    // constructor and destructor (declare below)
    // *********************************************
    LinkedList();
    ~LinkedList();

    // *********************************************
    // linked list operations (declare below)
    // *********************************************

    void displayList() const;
    void insertNode(T val);
    void deleteNode(T val);
    void reverse();
    void make_circular();
    void make_linear();
    
    
    friend int grader(); // DO NOT DELETE THIS LINE

};



// done for you. make sure to declare constructor above
// and call the list head pointer variable head or else this won't compile.
// define all other methods below
template <typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    if (!head) return;
    make_linear();
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void LinkedList<T>::displayList() const {
    if (!head) {
        return;
    }
    ListNode* current = head;
    do{
        cout << current->value << endl;
        current = current->next;
    } while (current && current != head);
}

template <typename T>
void LinkedList<T>::insertNode(T val) {
    make_linear();
    ListNode* newNode = new ListNode(val);
    if (!head || head->value >= val) {
        newNode->next = head;
        head = newNode;
        return;
    }

    ListNode* current = head;
    while (current->next && current->next->value < val) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

template <typename T>
void LinkedList<T>::deleteNode(T val) {
    if (!head) return;
    if (head->value == val) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    ListNode* current = head;
    while (current->next && current->next->value != val) {
        current = current->next;
    }
    if (!current->next || current->next == head) {
        cout << "Node not found." << endl;
        return;
    }

    ListNode* temp = current->next;
    current->next = current->next->next;
    delete temp;
}

template <typename T>
void LinkedList<T>::reverse() {
    if (!head || !head->next){
        return;
    }

    bool isCircular = false;
    if (head->next == head) {
        isCircular = true;
        make_linear();
    }
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    if (isCircular) {
        make_circular();
    }
}

template <typename T>
void LinkedList<T>::make_circular() {
    if (!head){
        return;
    }
    ListNode* current = head;
    while (current->next && current->next != head) {
        current = current->next;
    }
    if (current->next == head) {
        cout << "Linked List is already circular." << endl;
        return;
    }
    current->next = head;
}

template <typename T>
void LinkedList<T>::make_linear() {
    if (!head){
        return;
    }
    ListNode* current = head;
    while (current->next && current->next != head) {
        current = current->next;
    }
    if (!current->next) {
        cout << "Linked List is already linear." << endl;
        return;
    }
    current->next = nullptr;
}


#endif // DO NOT ADD CODE BELOW THIS LINE
