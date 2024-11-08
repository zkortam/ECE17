#include <iostream>
#include <cmath>
using namespace std;

/* This function returns the median value in 
 * an array of double values. 
 *
 * Parameters:
 *    double arr[]-- the array of data
 *    int n -- the size of arr[]
 *
 * Return value:
 *    double -- the median of the data
 */
double median(double arr[], int n);


/* This function returns the k-th largest values in 
 * an array of double values. 
 *
 * Parameters:
 *    double arr[]-- the array of data
 *    int n -- the size of arr[]
 *    int k -- the the k-th largest element to return
 *
 * Return value:
 *    double -- the k-th largest data value
 */
double kth_largest(double arr[], int n, int k);


/* This function returns the smallest absolute 
 * difference between all combinations of absolute
 * differences among the values of an array
 *
 * Parameters:
 *    int arr[]-- the array of data
 *    int n -- the size of arr[]
 *
 * Return value:
 *    int -- the smallest absolute difference between all combinations of elements in the array
 */
int min_abs_dif(int arr[], int n);

/* This function returns the standard deviation 
 * of all elements in an input array 
 *
 * Parameters:
 *    double arr[]-- the array of data
 *    int n -- the size of arr[]
 *
 * Return value:
 *    double -- standard deviation of all data in the input array
 */
double std_dev(double arr[], int n);

