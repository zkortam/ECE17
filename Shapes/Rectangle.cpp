#include "Rectangle.h"

// define Rectangle methods below


Rectangle::Rectangle(double width, double length): BasicShape(){
    this->length = length;
    this->width = width;
    calcArea();
}

void Rectangle::calcArea(){
    setArea(length*width);
}

double Rectangle::getWidth(){
    return this->width;
}

double Rectangle::getLength(){
    return this->length;
}

