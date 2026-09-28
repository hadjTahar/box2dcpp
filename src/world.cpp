#include <box2dcpp/world.h>
#include <box2d/box2d.h>
#include <cassert>
#include <iostream>


namespace Qx::Box2D {

World::World(private_ctor_t)
{
    m_bodies.reserve( 100 );
    auto opts = b2DefaultWorldDef();
    m_id      = b2CreateWorld( &opts );
}

World::~World()
{
    for ( const auto &body : m_bodies)
        b2DestroyBody( body.m_id );
    b2DestroyWorld( m_id );
}


Body *World::addBody()
{
    /// ## Find an other solution for pointers losing
    /// ## their references, perhaps std::move???
    ///

    if( m_bodies.size() >= m_bodies.capacity() ){
        std::cout << "World::addBody : Can't add more bodies, m_bodies will re-allocate and the pointers will lose "
                     "the references" << std::endl;
    }

    assert(m_bodies.size() < m_bodies.capacity() &&
           "World::addBody : Can't add more bodies, m_bodies will re-allocate and the pointers will lose "
           "the references ");


    m_bodies.emplace_back( Body::private_ctor_t{}, *this );
    return &m_bodies.back();
}

void World::setGravity(const b2Vec2 &vec)
{
    b2World_SetGravity( m_id, vec );
}



}
