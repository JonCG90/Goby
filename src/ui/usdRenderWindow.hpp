//
//  usdRenderWindow.hpp
//  Goby
//
//  Created by Jonathan Graham on 7/28/19.
//

#ifndef USDRENDERWINDOW_HPP
#define USDRENDERWINDOW_HPP

#include "openglwindow.hpp"

#include <pxr/usd/usd/stage.h>
#include <pxr/usdImaging/usdImagingGL/engine.h>

#include <QtGui/QMatrix4x4>
#include <QtGui/QOpenGLShaderProgram>
#include <QtGui/QScreen>

#include <QtCore/qmath.h>

#include <stdio.h>

class UsdRenderWindow : public OpenGLWindow
{
public:
    UsdRenderWindow();
    
    void initialize() override;
    void render() override;
    
private:
    GLuint m_posAttr;
    GLuint m_colAttr;
    GLuint m_matrixUniform;
    
    QOpenGLShaderProgram *m_program;
    int m_frame;
    
    pxr::UsdStageRefPtr m_stage;
    std::shared_ptr< pxr::UsdImagingGLEngine > m_engine;
};

#endif /* USDRENDERWINDOW_HPP */
