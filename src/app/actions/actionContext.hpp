//
//  actionContext.hpp
//  Goby
//
//  Created by Jonathan Graham on 8/21/19.
//

#ifndef GOBY_ACTIONCONTEXT_HPP
#define GOBY_ACTIONCONTEXT_HPP

#include <iostream>

namespace Goby
{

struct ActionContext;
using ActionContextPtr = std::shared_ptr< ActionContext >;

struct ActionContext
{
public:
    
    ActionContext() = default;
    virtual ~ActionContext() = default;
    
    static ActionContextPtr defaultContext();
};
    
} // namespace Goby

#endif /* GOBY_ACTIONCONTEXT_HPP */
