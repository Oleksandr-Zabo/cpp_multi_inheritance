#ifndef SHAPE_H
#define SHAPE_H

#include "lib.h"


class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

#endif // !SHAPE_H