//
//  rendererPlugin.cpp
//  Goby
//
//  Created by Jonathan Graham on 6/27/19.
//

#include "rendererPlugin.hpp"
#include "renderDelegate.hpp"

#include "pxr/imaging/hdx/rendererPluginRegistry.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the plugin
TF_REGISTRY_FUNCTION( TfType )
{
    HdxRendererPluginRegistry::Define< HdMarlinRendererPlugin >();
}

pxr::HdRenderDelegate* HdMarlinRendererPlugin::CreateRenderDelegate()
{
    return nullptr;
//    return new HdMarlinRendererDelegate();
}

pxr::HdRenderDelegate* HdMarlinRendererPlugin::CreateRenderDelegate( pxr::HdRenderSettingsMap const &i_settingsMap )
{
    return nullptr;
//    return new HdMarlinRendererDelegate(settingsMap);
}

void HdMarlinRendererPlugin::DeleteRenderDelegate( pxr::HdRenderDelegate* i_renderDelegate )
{
    delete i_renderDelegate;
}

bool HdMarlinRendererPlugin::IsSupported() const
{
    return true;
}

PXR_NAMESPACE_CLOSE_SCOPE
