#ifndef XF_INTERFACE_REACTIVE_H
#define XF_INTERFACE_REACTIVE_H

#include <string>
#include "xf/event.h"
#include "xf/eventstatus.h"

class XFDispatcherDefault;
class XFDispatcherActiveDefault;
class XFDispatcherPort;
class XFDispatcherActivePort;
class XFDispatcher;

namespace interface {

/**
 * @brief Interface to receive and process events.
 *
 * Interface that needs to be implemented by every class having a
 * behavior. Interface methods are needed by the other parts of the XF.
 *
 * This interface is used by the dispatcher to process events.
 */
class XFReactive
{
    // Only XFDispatchers should get access to the 'process' method
    friend class ::XFDispatcherDefault;
    friend class ::XFDispatcherActiveDefault;
    friend class ::XFDispatcherPort;
    friend class ::XFDispatcherActivePort;
    friend class ::XFDispatcher;

public:
    using TerminateBehavior = bool;

public:
    virtual ~XFReactive() = default;

    virtual void startBehavior() = 0;                               ///< Starts the behavior.
    virtual void pushEvent(XFEvent * pEvent) = 0;                   ///< Injects an event into the class.

    virtual bool deleteOnTerminate() const = 0;                     ///< Tells XF to delete behavior when receiving terminate event.
    virtual void setDeleteOnTerminate(bool deleteBehaviour) = 0;    ///< Sets/Clears the 'delete on terminate' property.

protected:
    virtual TerminateBehavior process(const XFEvent * pEvent) = 0;  ///< Called by the dispatcher to process an event.

protected:
    XFReactive() = default;
};

} // namespace interface
#endif // XF_INTERFACE_REACTIVE_H
