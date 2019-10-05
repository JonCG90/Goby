//
//  renderItem.hpp
//  Goby
//
//  Created by Jonathan Graham on 10/1/19.
//

#ifndef MARLIN_RENDERITEM_HPP
#define MARLIN_RENDERITEM_HPP

#include <iostream>

namespace marlin
{

class RenderItem
{
public:
    
    RenderItem( size_t i_type );
    ~RenderItem() = default;
    
    size_t getIdentifier() const;
    size_t getType() const;

private:
    
    size_t m_identifier;
    size_t m_type;
};
    
} // namespace marlin

#endif /* MARLIN_RENDERITEM_HPP */
