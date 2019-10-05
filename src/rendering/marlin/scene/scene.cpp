//
//  scene.cpp
//  Goby
//
//  Created by Jonathan Graham on 10/1/19.
//

#include "scene.hpp"

#import <OpenGL/gl3.h>

namespace marlin
{

void Scene::update()
{
    
}

void Scene::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
//    glViewport(0, 0, m_resolutionX, m_resolutionY);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    
}
    
} // namespace marlin
