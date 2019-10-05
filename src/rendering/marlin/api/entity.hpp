//
//  entity.hpp
//  Goby
//
//  Created by Jonathan Graham on 10/5/19.
//

#ifndef MARLIN_ENTITY_HPP
#define MARLIN_ENTITY_HPP

#include <iostream>

namespace marlin
{

enum class EntityType
{
    Cubemap,
    Material,
    Mesh,
    Scene,
    Texture,
    Invalid,
};

struct EntityHash;
    
class Entity
{
public:
    explicit Entity( EntityType type );
    Entity();
    ~Entity() = default;
    
    friend bool operator==( const Entity &i_lhs, const Entity &i_rhs );
    friend bool operator!=( const Entity &i_lhs, const Entity &i_rhs );
    friend bool operator>( const Entity &i_lhs, const Entity &i_rhs );
    friend bool operator<( const Entity &i_lhs, const Entity &i_rhs );
    friend bool operator>=( const Entity &i_lhs, const Entity &i_rhs );
    friend bool operator<=( const Entity &i_lhs, const Entity &i_rhs );

private:
    
    EntityType m_type;
    size_t m_identifier;
    
    friend struct EntityHash;
};

struct EntityHash
{
  
std::size_t operator()( Entity i_entity ) const {
    return i_entity.m_identifier;
}

};
    
} // namespace marlin

#endif /* MARLIN_ENTITY_HPP */
