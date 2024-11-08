#ifndef BASESHAPE_H
#define BASESHAPE_H

// declare BasicShape class below

class BasicShape{
    private:
        double area;

    public:
        BasicShape(double area=0);
        double getArea();
        void setArea(double area);
        //abstract
        virtual void calcArea() = 0;
};


#endif // do not add code after this line
