//
//  item.hpp
//  Goby
//
//  Created by Jonathan Graham on 10/27/18.
//  Copyright © 2018 Jonathan Graham. All rights reserved.
//

#ifndef CORAL_ITEM_HPP
#define CORAL_ITEM_HPP

#include <pxr/usd/usd/prim.h>

#include <vector>

namespace coral
{
    
class Item;
typedef std::vector< Item > Items;
    
class Item
{
        
public:
    
    explicit Item( const pxr::UsdPrim &i_prim );
    ~Item() = default;
    
    Item getParent() const;
    Items getSubItems() const;
    
    std::string getPath() const;
    const pxr::UsdPrim getInternalPrim() const;
    
    bool operator==( const Item &i_other ) const;
    bool operator!=( const Item &i_other ) const;
    
private:
    
    pxr::UsdPrim m_prim;
    
    Items m_children;
};
    
} // namespace coral

#endif /* CORAL_ITEM_HPP */
