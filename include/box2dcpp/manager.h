#ifndef MANAGER_H
#define MANAGER_H
#include "body.h"
#include "world.h"

namespace Qx::Box2D {


class Manager
{
public:
    World *createWorld();
    void step(float dltMs , int subStepCount);

protected:
    std::vector<World> m_worlds;
};


}

#endif // MANAGER_H
