#include "vehicle.h"

// define the underWarranty method
bool Vehicle::underWarranty(int currentYear){
    if(mileage > 30000 || (currentYear - year) > 3){
        return false;
    } else {
        return true;
    }
}

// define the monthlyPayment method
float Vehicle::monthlyPayment(int nYears, double downPayment, float interest){
    return ((interest / 12) * (cost - downPayment)) / (1 - pow(1 + (interest / 12), -(nYears * 12)));
}
