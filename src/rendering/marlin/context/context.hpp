//
//  context.hpp
//  Goby
//
//  Created by Jonathan Graham on 10/5/19.
//

#ifndef MARLIN_CONTEXT_HPP
#define MARLIN_CONTEXT_HPP

#include <marlin/api/entity.hpp>
#include <marlin/context/updateTask.hpp>
#include <marlin/scene/scene.hpp>

#include <unordered_map>
#include <queue>

namespace marlin
{

class Context
{
public:
    Context() = default;
    ~Context() = default;

    static Context & sharedContext();
    
    Context( Context const &i_context ) = delete;
    void operator=( Context const &i_context ) = delete;
    
    void flushUpdateQueue();
    
    void addScene( const Entity &i_entity, ScenePtr i_scene );
    void removeScene( const Entity &i_entity );
    
private:
    
    std::unordered_map< Entity, ScenePtr, EntityHash > m_scenes;
    std::queue< UpdateTaskPtr > m_updateQueue;
    
    std::mutex m_updateMutex;
    
private:
    
    void addUpdateTask( const std::function< void( Context& i_context ) > &i_task );
    
};
    
} // namespace marlin

#endif /* MARLIN_CONTEXT_HPP */
