#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "Circle.h"

// Generalized function template for selectionSort
template <typename T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            T temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

// specialized function template for selectionsort for circle class.
template <>
void selectionSort<Circle>(Circle arr[], int size) {
    for (int i = 0; i < size; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j].getArea() < arr[min].getArea()) {
                min = j;
            }
        }
        if (min != i) {
            Circle temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}


#endif // do not add code after this line
