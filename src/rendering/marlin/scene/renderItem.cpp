//
//  renderItem.cpp
//  Goby
//
//  Created by Jonathan Graham on 10/1/19.
//

#include "renderItem.hpp"

namespace marlin
{

RenderItem::RenderItem( size_t i_type )
: m_type( i_type )
{
    static uint64_t identifier = 0;
    m_identifier = identifier++;
}

size_t RenderItem::getIdentifier() const
{
    return m_identifier;
}

size_t RenderItem::getType() const
{
    return m_type;
}
    
} // namespace marlin
