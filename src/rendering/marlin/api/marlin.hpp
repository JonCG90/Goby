//
//  marlin.hpp
//  Goby
//
//  Created by Jonathan Graham on 10/5/19.
//

#ifndef MARLIN_HPP
#define MARLIN_HPP

#include <marlin/api/entity.hpp>

namespace marlin
{

Entity createScene();

void update();
void render( const Entity &i_scene );
    
} // namespace marlin

#endif /* MARLIN_HPP */
