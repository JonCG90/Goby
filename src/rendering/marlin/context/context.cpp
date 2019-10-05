//
//  context.cpp
//  Goby
//
//  Created by Jonathan Graham on 10/5/19.
//

#include "context.hpp"

namespace marlin
{

Context & Context::sharedContext()
{
    static Context shared;
    return shared;
}

void Context::flushUpdateQueue()
{
    std::queue< UpdateTaskPtr > updateQueue;
    
    // Swap queues so we don't need to hold onto the lock
    {
        std::lock_guard< std::mutex > lock( m_updateMutex );
        std::swap( updateQueue, m_updateQueue );
    }
    
    while ( !updateQueue.empty() )
    {
        UpdateTaskPtr task = updateQueue.front();
        updateQueue.pop();
          
        task->execute( *this );
    }
}

void Context::addScene( const Entity &i_entity, ScenePtr i_scene )
{
    auto task = [ i_entity, i_scene ]( Context& i_context ) {
        i_context.m_scenes[ i_entity ] = i_scene;
    };

    addUpdateTask( task );
}

void Context::removeScene( const Entity &i_entity )
{
    auto task = [ i_entity ]( Context& i_context ) {
        i_context.m_scenes.erase( i_entity );
    };
    addUpdateTask( task );
}

void Context::addUpdateTask( const std::function< void( Context& i_context ) > &i_task )
{
    UpdateTaskPtr updateTask = std::make_shared< UpdateTask >( *this, i_task );

    std::lock_guard< std::mutex > lock( m_updateMutex );
    m_updateQueue.push( updateTask );
}
    
} // namespace marlin
