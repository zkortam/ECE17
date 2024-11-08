#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "selectionSort.h"
using namespace std;

int main() {
    // Demonstrate a Circle.
    Circle c(2);


    // This should print "The area of the circle is 12.5664."
    cout << "The area of the circle is " << c.getArea() << "." << endl;


    // Demonstrate a Rectangle.
    Rectangle r(4, 2);

    // This should print "The area of the rectangle is 8."
    cout << "The area of the rectangle is " << r.getArea() << "." << endl;

    // Test array of type int
    int intArray[] = {5, 2, 8, 1, 3};
    int intArraySize = 5;

    // This should print "Original int array: 5 2 8 1 3"
    cout << "Original int array: ";
    for (int i = 0; i < intArraySize; ++i)
        cout << intArray[i] << " ";
    cout << endl;

    selectionSort(intArray, intArraySize);

    // This should print "Sorted int array: 1 2 3 5 8"
    cout << "Sorted int array: ";
    for (int i = 0; i < intArraySize; i++)
        cout << intArray[i] << " ";
    cout << endl;



    // Test array of type Circle
    Circle objArray[] = {Circle(5), Circle(3), Circle(2)};
    int objArraySize = 3;

    // This should print "Original Circle array: 78.5397 28.2743 12.5664"
    cout << "Original Circle array: ";
    for (int i = 0; i < objArraySize; i++)
        std::cout << objArray[i].getArea() << " ";
    cout << endl;

    selectionSort(objArray, objArraySize);

    // This should print "Sorted Circle array: 12.5664 28.2743 78.5397"
    cout << "Sorted Circle array: ";
    for (int i = 0; i < objArraySize; i++)
        std::cout << objArray[i].getArea() << " ";
    cout << endl;

}
