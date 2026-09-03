#include <box2dcpp/manager.h>
#include <box2d/box2d.h>

namespace Qx::Box2D {



World *Manager::createWorld()
{
    m_worlds.emplace_back( World::private_ctor_t{} );
    return &m_worlds.back();
}

void Manager::step(float dltMs, int subStepCount)
{
    const auto dltSec = dltMs / 1000.0f;
    for ( auto &world : m_worlds)
        b2World_Step( world.m_id, dltSec, subStepCount);
}

}
