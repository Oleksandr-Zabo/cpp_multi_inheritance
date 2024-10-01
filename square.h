#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

class Square : virtual public Shape {
protected:
	double side;
public:
	Square() {
		cout << "Square constructor" << endl;
		side = 0;
	}
	Square(double side) {
		cout << "Square constructor with param" << endl;
		this->side = side;
	}

	double area() const override {

		return side * side;
	}

	double circumference() const {
		return 4 * side;
	}
};

#endif // !SQUARE_H
