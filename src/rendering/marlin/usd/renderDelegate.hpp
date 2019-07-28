//
//  renderDelegate.hpp
//  Goby
//
//  Created by Jonathan Graham on 7/2/19.
//

#ifndef MARLIN_RENDER_DELEGATE_HPP
#define MARLIN_RENDER_DELEGATE_HPP

#include "pxr/imaging/hd/renderDelegate.h"

class HdMarlinRendererDelegate final : public pxr::HdRenderDelegate
{
    
public:
    
    HdMarlinRendererDelegate() = default;
    ~HdMarlinRendererDelegate() = default;
    
    const pxr::TfTokenVector & GetSupportedRprimTypes() const override;
    
    const pxr::TfTokenVector & GetSupportedSprimTypes() const override;
    
    const pxr::TfTokenVector & GetSupportedBprimTypes() const override;
    
//    pxr::HdRenderParam* GetRenderParam() const override;
//
//    pxr::HdResourceRegistrySharedPtr GetResourceRegistry() const override;

};

#endif /* MARLIN_RENDERER_DELEGATE_HPP */
