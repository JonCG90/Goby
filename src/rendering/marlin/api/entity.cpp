//
//  entity.cpp
//  Goby
//
//  Created by Jonathan Graham on 10/5/19.
//

#include "entity.hpp"

namespace marlin
{

Entity::Entity( EntityType i_type )
    : m_type( i_type )
{
    static size_t identifier = 0;
    m_identifier = identifier++;
}
    
Entity::Entity()
    : m_type( EntityType::Invalid ),
    m_identifier( 0 )
{
}
    
bool operator==(const Entity &i_lhs, const Entity &i_rhs)
{
    return i_lhs.m_identifier == i_rhs.m_identifier;
}
    
bool operator!=(const Entity &i_lhs, const Entity &i_rhs)
{
    return i_lhs.m_identifier != i_rhs.m_identifier;
}
    
bool operator>(const Entity &i_lhs, const Entity &i_rhs)
{
    return i_lhs.m_identifier > i_rhs.m_identifier;
}

bool operator<(const Entity &i_lhs, const Entity &i_rhs)
{
    return i_lhs.m_identifier < i_rhs.m_identifier;
}

bool operator>=(const Entity &i_lhs, const Entity &i_rhs)
{
    return i_lhs.m_identifier >= i_rhs.m_identifier;
}

bool operator<=(const Entity &i_lhs, const Entity &i_rhs)
{
    return i_lhs.m_identifier <= i_rhs.m_identifier;
}
    
} // namespace marlin
