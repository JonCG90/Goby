//
//  usdRenderWindow.cpp
//  Goby
//
//  Created by Jonathan Graham on 7/28/19.
//

#include "usdRenderWindow.hpp"

#include <app/actions/camera/cameraActionContext.hpp>
#include <math/conversion.hpp>

#include <iostream>

// Temp
#include <coral/schema/meshSchema.hpp>
#include <rendering/marlin/geometry/mesh.hpp>
#include <rendering/marlin/shading/material.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <testing/openGLRender.hpp>
#include "glm/gtc/matrix_transform.hpp"

static const std::string kSolidVertexShader = R"SHADER_SRC(
#version 410

layout (location = 0) in vec3 vertexPostion;
layout (location = 1) in vec3 vertexNormal;
layout (location = 2) in vec2 vertexTexCoord;
layout (location = 3) in vec4 vertexColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4( vertexPostion, 1.0 );
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
    : m_frame(0)
{
}

void UsdRenderWindow::initialize()
{
    Goby::RenderCamera camera;
    camera.position = vec3d( 0.0, 0.0, 60.0 );
    camera.target = vec3d( 0.0, 0.0, 0.0 );
    camera.up = vec3d( 0.0, 1.0, 0.0 );

    m_cameraController.reset( camera );
    
    m_scene.load( "/Users/jongraham/Documents/Models/Kitchen_set/assets/Bottle/Bottle.usd" );
//    m_scene.load( "/Users/jongraham/Documents/Models/Kitchen_set/Kitchen_set.usd" );
//    coral::Items items = m_scene.getAllItems();
//
//    for ( const coral::Item &item : items )
//    {
//        std::cout << item.getPath() << std::endl;
//        coral::MeshSchema mesh = coral::MeshSchema( item );
//        coral::MeshPolygons geom = mesh.getPolygons();
//    }
}

void UsdRenderWindow::render()
{
    const qreal scale = devicePixelRatio();
    glViewport( 0, 0, width() * scale, height() * scale );
    
    glClear( GL_COLOR_BUFFER_BIT );
    
    mat4f projection = glm::perspective( 60.0f, 4.0f / 3.0f, 0.1f, 100.0f );
    mat4d view = m_cameraController.getView();
        
    QMatrix4x4 matrix;
    matrix.rotate( 100.0f * m_frame / screen()->refreshRate(), 0, 1, 0 );
    
    marlin::Material material;
    material.update( kSolidVertexShader, kSolidFragmentShader );
    
    mat4f model = glm::make_mat4( matrix.data() );
    
    material.setParameter( "model", model );
    material.setParameter( "view", convertType< float >( view ) );
    material.setParameter( "projection", projection );

    material.setParameter( "albedo", vec4f( 1.0, 1.0, 0.0, 0.5 ) );

    material.load();
    material.bind();
    
    coral::Items items = m_scene.getAllItems();
    
    for ( const coral::Item &item : items )
    {
        coral::MeshSchema meshSchema = coral::MeshSchema( item );
        coral::MeshPolygons polygons = meshSchema.getPolygons();
        
        marlin::MeshGeom geom;
        geom.points = polygons.points;
        geom.normals = polygons.normals;
        geom.texCoords = polygons.texCoords;
        geom.colors = polygons.colors;
        
        geom.faceVertexIndices = polygons.faceVertexIndices;
        geom.faceVertexCounts = polygons.faceVertexCounts;

        marlin::Mesh mesh( geom );
        mesh.load();
        mesh.render();
        mesh.unload();
    }
    
    material.unbind();
    material.unload();
    
    ++m_frame;
}

Goby::ActionContextPtr UsdRenderWindow::getContext()
{
    return Goby::CameraActionContext::context( &m_cameraController );
}
