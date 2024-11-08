#include <iostream>
#include "helpers.h"
using namespace std;

int main() {
    // define an array of doubles
    const int size = 5; 
    double my_double_arr[size] = {7.5, 4.3, 9.2, 1.5, 4.6}; 

    // call median, kth_largest, and std_dev functions to test them
    double med = median(my_double_arr, size); 
    cout << "Median: " << med << endl; // should print: Median: 4.6

    double k = kth_largest(my_double_arr, size, 2);
    cout << "K-th largest value: " << k << endl; // should print: K-th largest value: 7.5

    double std = std_dev(my_double_arr, size);
    cout << "Standard deviation is: " << std << endl; // should print: Standard deviation is: 2.67985


    // define int array to test min_abs_dif
    int my_int_array[] = {7, 2, 4, 11, 1}; 
    int dif = min_abs_dif(my_int_array, 5); 
    cout << "Minimum absolute difference is: " << dif << endl; // should print: Minimum absolute difference is: 1

    return 0; 
}
