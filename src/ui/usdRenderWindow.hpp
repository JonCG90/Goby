//
//  usdRenderWindow.hpp
//  Goby
//
//  Created by Jonathan Graham on 7/28/19.
//

#ifndef USDRENDERWINDOW_HPP
#define USDRENDERWINDOW_HPP

#include "openglwindow.hpp"

#include <app/shortcuts/shortcutReceiver.hpp>
#include <app/camera/cameraController.hpp>

#include <coral/scene.hpp>

#include <pxr/usd/usd/stage.h>
#include <pxr/usdImaging/usdImagingGL/engine.h>

#include <QtGui/QMatrix4x4>
#include <QtGui/QOpenGLShaderProgram>
#include <QtGui/QScreen>

#include <QtCore/qmath.h>

#include <stdio.h>

class UsdRenderWindow : public OpenGLWindow, public Goby::ShortcutReceiver
{
public:
    UsdRenderWindow();
    
    void initialize() override;
    void render() override;
    
    Goby::ActionContextPtr getContext() override;
    
private:
    
    int m_frame;
    
    coral::Scene m_scene;
    Goby::CameraController m_cameraController;
};

#endif /* USDRENDERWINDOW_HPP */
