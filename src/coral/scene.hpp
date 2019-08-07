//
//  scene.hpp
//  Goby
//
//  Created by Jonathan Graham on 10/27/18.
//  Copyright © 2018 Jonathan Graham. All rights reserved.
//

#ifndef CORAL_SCENE_HPP
#define CORAL_SCENE_HPP

#include <coral/item.hpp>

#include <pxr/usd/usd/stage.h>

#include <iostream>

namespace coral
{
    
class Scene
{
    
public:
    
    Scene();
    ~Scene() = default;
    
    void load( const std::string &path );
    bool isLoaded() const;
    
    Item getRoot() const;
    Item getItemAtPath( const std::string &path ) const;
    Items getAllItems() const;
    
private:
    
    bool m_loaded;
    
    pxr::UsdStageRefPtr m_stage;
    pxr::UsdPrim m_root;
};
    
} // namespace coral

#endif /* CORAL_SCENE_HPP */
