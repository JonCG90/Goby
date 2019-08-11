//
//  geometry.hpp
//  Goby
//
//  Created by Jonathan Graham on 8/11/19.
//

#ifndef MARLIN_GEOMETRY_HPP
#define MARLIN_GEOMETRY_HPP

#include <math/math.hpp>

#include <vector>

namespace marlin
{

struct MeshGeom
{
    std::vector< vec3f > points;
    std::vector< vec3f > normals;
    std::vector< vec4f > colors;
    std::vector< vec2f > texCoords;
    
    std::vector< size_t > faceVertexCounts;
    std::vector< size_t > faceVertexIndices;
};
    
} // namespace marlin

#endif /* MARLIN_GEOMETRY_HPP */
