#ifndef SHAPE_H
#define SHAPE_H

#include "types.h"

namespace Qx::Box2D {


class Body;

class Shape
{
    friend class Body;
    struct private_ctor_t {};


    Shape(){}

public:

    Shape(private_ctor_t,
          const Body &body,
          const Qx::Box2D::Polygon &polygon);
    Shape(private_ctor_t,
          const Body &body,
          const Qx::Box2D::Circle  &circle);
    Shape(private_ctor_t){}

    void setDensity( float density, bool updateBodyMass);
    void setRestitution( float restitution);


private:
    b2ShapeId m_shapeId;
};



}

#endif // SHAPE_H
