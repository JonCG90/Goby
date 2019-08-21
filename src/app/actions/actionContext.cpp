//
//  actionContext.cpp
//  Goby
//
//  Created by Jonathan Graham on 8/21/19.
//

#include "actionContext.hpp"

namespace Goby
{
    
ActionContextPtr ActionContext::defaultContext()
{
    return std::make_shared< ActionContext >();
}
    
} // namespace Goby
