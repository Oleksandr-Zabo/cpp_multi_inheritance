#ifndef CIRCLE_IN_SQUARE
#define CIRCLE_IN_SQUARE

#include "circle.h"
#include "square.h"

class CircleInSquare : public Circle, public Square {
public:
    CircleInSquare(double side_length) : Square(side_length), Circle(side_length / 2) {}

    double area() const override {
        return Circle::area();
    }

    void description() const {
        cout << "Circle with radius " << radius << " inscribed in a square with side " << side << "." << endl;
    }
};
#endif // !CIRCLE_IN_SQUARE
