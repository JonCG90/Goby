//
//  marlin.cpp
//  Goby
//
//  Created by Jonathan Graham on 10/5/19.
//

#include "marlin.hpp"

#include <marlin/context/context.hpp>

namespace marlin
{

Entity createScene()
{
    Entity sceneEntity( EntityType::Scene );
    
    ScenePtr scene = std::make_shared< Scene >();
    Context::sharedContext().addScene( sceneEntity, scene );

    return sceneEntity;
}

void update()
{
    Context::sharedContext().flushUpdateQueue();
}

void render( const Entity &i_scene )
{
    
}
    
} // namespace marlin
