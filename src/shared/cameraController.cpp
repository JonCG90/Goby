//
//  cameraController.cpp
//  Goby
//
//  Created by Jonathan Graham on 8/15/19.
//

#include "cameraController.hpp"

CameraController::CameraController()
    : m_type( CameraContolType::Fly )
{
}

void CameraController::update( double i_dx, double i_dy )
{
    switch ( m_type ) {
        case CameraContolType::Fly:
            
            break;
        case CameraContolType::Orbit:
            
            break;
        default:
            break;
    }
}
