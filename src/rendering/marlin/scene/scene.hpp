//
//  scene.hpp
//  Goby
//
//  Created by Jonathan Graham on 10/1/19.
//

#ifndef MARLIN_SCENE_HPP
#define MARLIN_SCENE_HPP

#include "renderItem.hpp"

#include <memory>
#include <vector>

namespace marlin
{

class Scene
{
public:
    
    Scene() = default;
    ~Scene() = default;
    
    void update();
    
    void render();
    
private:
    
    std::vector< RenderItem > m_renderList;
};

using ScenePtr = std::shared_ptr< Scene >;
    
} // namespace marlin

#endif /* MARLIN_SCENE_HPP */
