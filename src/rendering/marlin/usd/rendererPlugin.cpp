//
//  rendererPlugin.cpp
//  Goby
//
//  Created by Jonathan Graham on 6/27/19.
//

#include "rendererPlugin.hpp"

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
