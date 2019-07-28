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

PXR_NAMESPACE_OPEN_SCOPE

class HdMarlinRendererPlugin final : public HdxRendererPlugin
{
    
public:
    
    /// Constructor
    HdMarlinRendererPlugin() = default;
    
    /// Destructor
    ~HdMarlinRendererPlugin() override = default;
    
    
    HdRenderDelegate* CreateRenderDelegate() override;
    
    HdRenderDelegate* CreateRenderDelegate( HdRenderSettingsMap const &i_settingsMap ) override;
    
    void DeleteRenderDelegate( HdRenderDelegate* i_renderDelegate ) override;
    
    bool IsSupported() const override;
    
private:
    
    // Disable copying.
    HdMarlinRendererPlugin( const HdMarlinRendererPlugin & ) = delete;
    HdMarlinRendererPlugin & operator =( const HdMarlinRendererPlugin & ) = delete;
};

PXR_NAMESPACE_CLOSE_SCOPE

#endif /* MARLIN_RENDERER_PLUGIN_HPP */
