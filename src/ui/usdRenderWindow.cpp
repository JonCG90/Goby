//
//  usdRenderWindow.cpp
//  Goby
//
//  Created by Jonathan Graham on 7/28/19.
//

#include "usdRenderWindow.hpp"

#include <iostream>

// Temp
#include <coral/schema/meshSchema.hpp>
#include <rendering/marlin/geometry/mesh.hpp>
#include <rendering/marlin/shading/material.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <testing/openGLRender.hpp>

static const std::string kSolidVertexShader = R"SHADER_SRC(
#version 410

layout (location = 0) in vec3 vertexPostion;
layout (location = 1) in vec3 vertexNormal;
layout (location = 2) in vec2 vertexTexCoord;
layout (location = 3) in vec4 vertexColor;

uniform mat4 matrix;

void main()
{
    gl_Position = matrix * vec4( vertexPostion, 1.0 );
}

)SHADER_SRC";

static const std::string kSolidFragmentShader = R"SHADER_SRC(
#version 410

out vec4 FragColor;

uniform vec4 albedo;

void main() {
    FragColor = albedo;
}

)SHADER_SRC";

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
    m_program->addShaderFromSourceCode( QOpenGLShader::Vertex, kSolidVertexShader.c_str() );
    m_program->addShaderFromSourceCode( QOpenGLShader::Fragment, kSolidFragmentShader.c_str() );
    m_program->link();
    m_posAttr = m_program->attributeLocation( "posAttr" );
    m_colAttr = m_program->attributeLocation( "colAttr" );
    m_matrixUniform = m_program->uniformLocation( "matrix" );
    
    m_scene.load( "/Users/jongraham/Documents/Models/Kitchen_set/Kitchen_set.usd" );
    coral::Items items = m_scene.getAllItems();
    
    for ( const coral::Item &item : items )
    {
        std::cout << item.getPath() << std::endl;
        coral::MeshSchema mesh = coral::MeshSchema( item );
        coral::MeshPolygons geom = mesh.getPolygons();
    }
}

void UsdRenderWindow::render()
{
    renderQuad();
    return;
    
    const qreal scale = devicePixelRatio();
    glViewport( 0, 0, width() * scale, height() * scale );
    
    glClear( GL_COLOR_BUFFER_BIT );
    
//    m_program->bind();
    
    QMatrix4x4 matrix;
    matrix.perspective( 60.0f, 4.0f / 3.0f, 0.1f, 100.0f );
    matrix.translate(0, 0, -2);
    matrix.rotate( 100.0f * m_frame / screen()->refreshRate(), 0, 1, 0 );
    
//    m_program->setUniformValue( m_matrixUniform, matrix );
    
    marlin::Material material;
    material.update( kSolidVertexShader, kSolidFragmentShader );
    
    mat4f m = glm::make_mat4( matrix.data() );
    
    material.setParameter( "matrix", m );
    material.setParameter( "albedo", vec4f( 1.0, 1.0, 0.0, 0.5 ) );

    material.load();
    material.bind();
    
    GLfloat vertices[] = {
        0.0f, 0.707f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f
    };
    
    GLfloat colors[] = {
        1.0f, 1.0f, 0.0f,
        1.0f, 1.0f, 0.0f,
        1.0f, 1.0f, 0.0f
    };
    
    marlin::MeshGeom geom;
    
    geom.points = {
        vec3f( 0.0f,  0.707f, 0.0f ),
        vec3f( -0.5f, -0.5f,  0.0f ),
        vec3f( 0.5f,  -0.5f,  0.0f )
    };
    
    geom.colors = {
        vec4f( 1.0f, 1.0f, 0.0f, 1.0f ),
        vec4f( 1.0f, 1.0f, 0.0f, 1.0f ),
        vec4f( 1.0f, 1.0f, 0.0f, 1.0f )
    };
    
    geom.faceVertexCounts = { 3 };
    geom.faceVertexIndices = { 0, 1, 2 };

    marlin::Mesh mesh( geom );
    mesh.load();
    mesh.render();
    mesh.unload();
    
//    glVertexAttribPointer( m_posAttr, 3, GL_FLOAT, GL_FALSE, 0, vertices );
//    glVertexAttribPointer( m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colors );
//
//    glEnableVertexAttribArray( 0 );
//    glEnableVertexAttribArray( 1 );
//
//    glDrawArrays( GL_TRIANGLES, 0, 3 );
//
//    glDisableVertexAttribArray( 1 );
//    glDisableVertexAttribArray( 0 );
//
//    m_program->release();
    
    ++m_frame;
}
