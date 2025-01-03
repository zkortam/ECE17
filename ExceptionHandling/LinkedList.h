#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdexcept>
#include <string>
using namespace std;

class LinkedList {
private:
    // declare a struct for the nodes and data members below
    struct ListNode {
        int month;
        double price;
        ListNode* next;

        ListNode(int m, double p, ListNode* n = nullptr) : month(m), price(p), next(n) {}
    };

    ListNode* head;
    int size;


public:
    // *********************************************
    // constructor and destructor (declare below)
    // *********************************************
        LinkedList();
        ~LinkedList();
    



    // *********************************************
    // exception classes (declare and define below)
    // *********************************************

    class EmptyListException : public exception {
        public:
            const char* what() const noexcept override{
                return "The linked list is empty.";
            }
    };

    class NegativeIndex : public out_of_range {
        public:
            explicit NegativeIndex(const string& msg): out_of_range(msg) {}
    };

    class LargeIndex : public out_of_range {
        public:
            explicit LargeIndex(const string& msg): out_of_range(msg) {}
    };


    // *********************************************
    // linked list operations (declare below)
    // *********************************************

    void insert(int month, double price);
    void deleteNode(double price);
    double find(int month) const;
    void displayList() const;
    int getSize() const;
    void appendNode(int month, double price);

    void bubbleSort();
    LinkedList averageMonthlyPrice() const;

    double operator[](int index) const;

    friend int grader(); // DO NOT DELETE THIS LINE

};

#endif 
