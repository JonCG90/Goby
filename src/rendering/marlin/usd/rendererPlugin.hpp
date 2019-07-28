//
//  rendererPlugin.hpp
//  Goby
//
//  Created by Jonathan Graham on 6/27/19.
//

#ifndef MARLIN_RENDERER_PLUGIN_HPP
#define MARLIN_RENDERER_PLUGIN_HPP

#include "renderDelegate.hpp"

#include "pxr/pxr.h"
#include "pxr/imaging/hdx/rendererPlugin.h"

class HdMarlinRendererPlugin final : public pxr::HdxRendererPlugin
{
    
public:
    
    HdMarlinRendererPlugin() = default;
    ~HdMarlinRendererPlugin() override = default;
    
    pxr::HdRenderDelegate* CreateRenderDelegate() override;
    
    pxr::HdRenderDelegate* CreateRenderDelegate( pxr::HdRenderSettingsMap const &i_settingsMap ) override;
    
    void DeleteRenderDelegate(pxr::HdRenderDelegate* i_renderDelegate) override;
    
    bool IsSupported() const override;
    
private:
    
    // This class does not support copying.
    HdMarlinRendererPlugin( const HdMarlinRendererPlugin & ) = delete;
    HdMarlinRendererPlugin & operator =( const HdMarlinRendererPlugin & ) = delete;
};

#endif /* MARLIN_RENDERER_PLUGIN_HPP */
