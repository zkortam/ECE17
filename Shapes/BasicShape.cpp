#include "BasicShape.h"

// define BasicShape methods below

BasicShape::BasicShape(double area){
    this->area = area;
}

double BasicShape::getArea(){
    return this->area;
}

void BasicShape::setArea(double area){
    this->area = area;
}
