#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "BasicShape.h"

// declare Rectangle class below

class Rectangle : public BasicShape{
    private:
        double width;
        double length;
    public: 
        Rectangle(double length=0, double width =0);
        void calcArea() override;
        double getWidth();
        double getLength();
};



#endif // do not add code after this line
