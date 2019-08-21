//
//  shortcutFilter.hpp
//  Goby
//
//  Created by Jonathan Graham on 8/20/19.
//

#ifndef GOBY_SHORTCUTFILTER_HPP
#define GOBY_SHORTCUTFILTER_HPP

#include <QObject>

namespace Goby
{

class ShortcutEventFilter : public QObject
{
    Q_OBJECT
    
public:
    
    explicit ShortcutEventFilter( QObject* i_parent );
    ~ShortcutEventFilter() = default;
    
    bool eventFilter( QObject* i_obj, QEvent* i_event) override;
};
    
} // namespace Goby

#endif /* GOBY_SHORTCUTFILTER_HPP */
