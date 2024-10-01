#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : virtual public Shape {
protected:
    double radius;
public:
    Circle() {
        cout << "Circle constructor" << endl;
        radius = 0;
    }
    Circle(double radius) {
        cout << "Circle constructor with param" << endl;
        this->radius = radius;
    }

    double area() const override {
        return M_PI * radius * radius;
    }

    double circumference() const {
        return 2 * M_PI * radius;
    }

};

#endif // !CIRCLE_H
