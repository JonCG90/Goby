//
//  shortcutReceiver.hpp
//  Goby
//
//  Created by Jonathan Graham on 8/20/19.
//

#ifndef GOBY_SHORTCUTRECEIVER_HPP
#define GOBY_SHORTCUTRECEIVER_HPP

#include <app/actions/actionContext.hpp>

namespace Goby
{
    
class ShortcutReceiver
{
public:
    
    ShortcutReceiver() = default;
    virtual ~ShortcutReceiver() = default;
    
    virtual ActionContextPtr getContext() = 0;
};
    
} // namespace Goby

#endif /* GOBY_SHORTCUTRECEIVER_HPP */
