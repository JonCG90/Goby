//
//  cameraSchema.hpp
//  Goby
//
//  Created by Jonathan Graham on 8/18/19.
//

#ifndef CORAL_CAMERA_SCHEMA_HPP
#define CORAL_CAMERA_SCHEMA_HPP

#include <coral/item.hpp>

#include <pxr/usd/usd/prim.h>
#include <pxr/usd/usdGeom/mesh.h>
#include <pxr/usd/usdGeom/camera.h>

namespace coral
{
    
class CameraSchema
{
public:
    
    explicit CameraSchema( const Item &i_item );
    
private:
    
    pxr::UsdGeomCamera m_camera;
    
};
    
} // namespace coral

#endif /* CORAL_CAMERA_SCHEMA_HPP */
