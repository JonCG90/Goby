//
//  usdRenderWindow.cpp
//  Goby
//
//  Created by Jonathan Graham on 7/28/19.
//

#include "usdRenderWindow.hpp"

#include <iostream>

UsdRenderWindow::UsdRenderWindow()
: m_program(0)
, m_frame(0)
{
}

static const char *vertexShaderSource =
"attribute highp vec4 posAttr;\n"
"attribute lowp vec4 colAttr;\n"
"varying lowp vec4 col;\n"
"uniform highp mat4 matrix;\n"
"void main() {\n"
"   col = colAttr;\n"
"   gl_Position = matrix * posAttr;\n"
"}\n";

static const char *fragmentShaderSource =
"varying lowp vec4 col;\n"
"void main() {\n"
"   gl_FragColor = col;\n"
"}\n";

void UsdRenderWindow::initialize()
{
    m_program = new QOpenGLShaderProgram( this );
    m_program->addShaderFromSourceCode( QOpenGLShader::Vertex, vertexShaderSource );
    m_program->addShaderFromSourceCode( QOpenGLShader::Fragment, fragmentShaderSource );
    m_program->link();
    m_posAttr = m_program->attributeLocation( "posAttr" );
    m_colAttr = m_program->attributeLocation( "colAttr" );
    m_matrixUniform = m_program->uniformLocation( "matrix" );
    
    m_stage = pxr::UsdStage::Open( "/Users/jongraham/Documents/Models/Kitchen_set/Kitchen_set.usd" );
    //m_stage = pxr::UsdStage::Open( "/Users/jongraham/Documents/Models/Kitchen_set/assets/Bottle/Bottle.usd" );
    
    pxr::SdfPathVector excludedPaths;
    m_engine = std::make_shared< pxr::UsdImagingGLEngine >( m_stage->GetPseudoRoot().GetPath(), excludedPaths );
    m_engine->SetRendererPlugin( pxr::TfToken( "HdMarlinRendererPlugin" ) );
    
    pxr::TfTokenVector plugins = m_engine->GetRendererPlugins();
    for ( const auto &plugin : plugins )
    {
        std::cout << m_engine->GetRendererDisplayName( plugin ) << std::endl;
    }
    std::cout << plugins.size();
}

void UsdRenderWindow::render()
{
    const qreal scale = devicePixelRatio();
    glViewport( 0, 0, width() * scale, height() * scale );
    
    glClear( GL_COLOR_BUFFER_BIT );
    
    m_program->bind();
    
    QMatrix4x4 matrix;
    matrix.perspective( 60.0f, 4.0f / 3.0f, 0.1f, 100.0f );
    matrix.translate(0, 0, -2);
    matrix.rotate( 100.0f * m_frame / screen()->refreshRate(), 0, 1, 0 );
    
    m_program->setUniformValue( m_matrixUniform, matrix );
    
    GLfloat vertices[] = {
        0.0f, 0.707f,
        -0.5f, -0.5f,
        0.5f, -0.5f
    };
    
    GLfloat colors[] = {
        1.0f, 1.0f, 0.0f,
        1.0f, 1.0f, 0.0f,
        1.0f, 1.0f, 0.0f
    };
    
    glVertexAttribPointer( m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, vertices );
    glVertexAttribPointer( m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colors );
    
    glEnableVertexAttribArray( 0 );
    glEnableVertexAttribArray( 1 );
    
    glDrawArrays( GL_TRIANGLES, 0, 3 );
    
    glDisableVertexAttribArray( 1 );
    glDisableVertexAttribArray( 0 );
    
    m_program->release();
    
    ++m_frame;
    
    const pxr::UsdPrim root = m_stage->GetPseudoRoot();
    pxr::UsdImagingGLRenderParams params;
    
    m_engine->Render( root, params );
}
