//
//  scene.cpp
//  Goby
//
//  Created by Jonathan Graham on 10/27/18.
//  Copyright © 2018 Jonathan Graham. All rights reserved.
//

#include <coral/scene.hpp>

#include "pxr/usd/usd/primRange.h"

using namespace pxr;

namespace coral
{
    
Scene::Scene()
    : m_loaded( false )
    , m_stage( nullptr )
{}

void Scene::load( const std::string &path )
{
    UsdStageRefPtr stage = UsdStage::Open( path );
    
    if ( stage )
    {
        // Get the scene root
        UsdPrim rootPrim = stage->GetDefaultPrim();
        if ( !rootPrim )
        {
            rootPrim = stage->GetPseudoRoot();
        }
        
        if ( rootPrim )
        {
            m_root = rootPrim;
            m_stage = stage;
            m_loaded = true;
        }
    }
}
    
bool Scene::isLoaded() const
{
    return m_loaded;
}
    
Item Scene::getRoot() const
{
    return Item( m_root );
}
    
Item Scene::getItemAtPath( const std::string &path ) const
{
    UsdPrim prim;
    
    if ( m_loaded )
    {
        prim = m_stage->GetPrimAtPath( SdfPath( path ) );
    }
    
    return Item( prim );
}
    
Items Scene::getAllItems() const
{
    UsdPrimRange range = UsdPrimRange::PreAndPostVisit( m_root );
    Items items;
    
    for ( auto itr = range.begin(); itr != range.end(); itr++ )
    {
        if ( !itr.IsPostVisit() )
        {
            Item item( *itr );
            items.push_back( item );
        }
    }
    
    return items;
}
    
} // namespace coral
