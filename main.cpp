#include "circle_in_square.h"

int main() {
    CircleInSquare shape(10);
    shape.description();
    cout << "Square of circle: " << shape.Circle::area() << endl;
    cout << "Perimetr of square: " << shape.Square::circumference() << endl;
    return 0;
}