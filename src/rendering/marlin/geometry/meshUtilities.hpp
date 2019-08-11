//
//  meshUtilities.hpp
//  Goby
//
//  Created by Jonathan Graham on 8/11/19.
//

#ifndef MARLIN_MESHUTILITIES_HPP
#define MARLIN_MESHUTILITIES_HPP

#include "geometry.hpp"

#import <OpenGL/gl3.h>

#include <iostream>
#include <vector>

namespace marlin
{
    
namespace utils
{
    
bool convertMeshToGlArrays( const MeshGeom &i_geom,
                            std::vector< GLfloat > &o_points,
                            std::vector< GLfloat > &o_normals,
                            std::vector< GLfloat > &o_colors,
                            std::vector< GLfloat > &o_texCoords,
                            std::vector< GLuint > &o_indices );
        
} // namespace utils
    
} // namespace marlin

#endif /* MARLIN_MESHUTILITIES_HPP */
