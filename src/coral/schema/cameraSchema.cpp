//
//  cameraSchema.cpp
//  Goby
//
//  Created by Jonathan Graham on 8/18/19.
//

#include "cameraSchema.hpp"

namespace coral
{
    
CameraSchema::CameraSchema( const Item &i_item )
    : m_camera( i_item.getInternalPrim() )
{
        
}
    
} // namespace coral
