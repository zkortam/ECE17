#include "Circle.h"
#include <cmath>

// define Circle methods below

Circle::Circle(double radius): BasicShape(){
    (this->radius) = radius;
    calcArea();
}

void Circle::calcArea(){
    setArea((3.1415)*(pow(this->radius,2)));
}
double Circle::getArea(){
    return BasicShape::getArea();
}

