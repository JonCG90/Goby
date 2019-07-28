//
//  renderDelegate.cpp
//  Goby
//
//  Created by Jonathan Graham on 7/2/19.
//

#include "renderDelegate.hpp"

const pxr::TfTokenVector & HdMarlinRendererDelegate::GetSupportedRprimTypes() const
{
    static const pxr::TfTokenVector supportedRprims = { pxr::HdPrimTypeTokens->mesh };
    return supportedRprims;
}

const pxr::TfTokenVector & HdMarlinRendererDelegate::GetSupportedSprimTypes() const
{
    static const pxr::TfTokenVector supportedSprims = { pxr::HdPrimTypeTokens->camera };
    return supportedSprims;
}

const pxr::TfTokenVector & HdMarlinRendererDelegate::GetSupportedBprimTypes() const
{
    static const pxr::TfTokenVector supportedBprims = { pxr::HdPrimTypeTokens->renderBuffer };
    return supportedBprims;
}

//pxr::HdRenderParam* HdMarlinRendererDelegate::GetRenderParam() const
//{
//    
//}
//
//pxr::HdResourceRegistrySharedPtr HdMarlinRendererDelegate::GetResourceRegistry() const
//{
//    
//}
