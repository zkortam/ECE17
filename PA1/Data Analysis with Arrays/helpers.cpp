#include "helpers.h"
#include <algorithm> 
#include <cmath>

double median(double arr[], int n) {
    if (n<1){
        cout<<"Invalid input length."<<endl;
        return 0;
    }
    double temp[n];
    for(int i=0; i<n; i++){
        temp[i] = arr[i];
    }

    sort(temp, temp + n);

    if(n % 2 == 0){
        return (temp[n / 2 - 1] + temp[n / 2]) / 2.0;
    } else {
        return temp[n/2];
    }
}

double kth_largest(double arr[], int n, int k) {
    if (n < 1){
        cout<<"Invalid length for input array."<<endl;
        return 0;
    }
    if (k < 1 | k > n){
        cout<<"Invalid k-th element."<<endl;
        return 0;
    }

    double temp[n];
    for(int i=0; i<n; i++){
        temp[i] = arr[i];
    }

    nth_element(temp, temp + n - k, temp + n);
    return temp[n - k];

}

int min_abs_dif(int arr[], int n) {
    if (n < 1) {
        cout << "Invalid input length." << endl;
        return 0;
    }

    int temp[n];
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }

    sort(temp, temp + n);

    int min_diff = abs(temp[1] - temp[0]);
    for (int i = 1; i < n - 1; i++) {
        int diff = abs(temp[i + 1] - temp[i]);
        if (diff < min_diff) {
            min_diff = diff;
        }
    }
    return min_diff;
}


double std_dev(double arr[], int n) {
    if (n < 1) {
        cout << "Invalid input length." << endl;
        return 0;
    }

    double mean = 0;
    for (int i = 0; i < n; i++) {
        mean += arr[i];
    }
    mean /= n;

    double variance = 0;
    for (int i = 0; i < n; i++) {
        variance += (arr[i] - mean) * (arr[i] - mean);
    }
    variance /= n;
    return sqrt(variance);
}
