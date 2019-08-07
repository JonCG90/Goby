//
//  item.cpp
//  Goby
//
//  Created by Jonathan Graham on 10/27/18.
//  Copyright © 2018 Jonathan Graham. All rights reserved.
//

#include "item.hpp"

using namespace pxr;

namespace coral
{
    
Item::Item( const UsdPrim &i_prim )
    : m_prim( i_prim )
{}
    
Item Item::getParent() const
{
    return Item( m_prim.GetParent() );
}

Items Item::getSubItems() const
{
    // TODO Make this better
    UsdPrimSiblingRange primChildren = m_prim.GetChildren();
    Items children;
    
    for ( const auto &child : primChildren )
    {
        children.push_back( Item( child ) );
    }
    
    return children;
}
    
std::string Item::getPath() const
{
    SdfPath path = m_prim.GetPath();
    return path.GetString();
}
    
const pxr::UsdPrim Item::getInternalPrim() const
{
    return m_prim;
}
    
bool Item::operator==( const Item &i_other ) const
{
    return m_prim == i_other.m_prim;
}
    
bool Item::operator!=( const Item &i_other ) const
{
    return m_prim != i_other.m_prim;
}
    
} // namespace coral
