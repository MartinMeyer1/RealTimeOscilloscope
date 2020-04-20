#ifndef XF_DISPATCHER_ACTIVE_H
#define XF_DISPATCHER_ACTIVE_H

#include <config/xf-config.h>

#if (USE_XF_DISPATCHER_ACTIVE_DEFAULT_IMPLEMENTATION != 0)

#include "xf/interface/dispatcher.h"
#include "xf/interface/thread.h"
#include "xf/interface/mutex.h"

/*
 * Please specify/include the XFEventQueuePort class in the xf-config file!
 */

/** @ingroup port_default
 *  @{
 */

/**
 * @brief A dispatcher implementation which may be executed using an internal thread.
 *
 * The active dispatcher internally requests a Thread from the XFResourceFactory and
 * starts it with the start() method. The thread itself is responsible to execute the 
 * protected method execute().
 */
class XFDispatcherActiveDefault : public interface::XFThreadEntryPointProvider,
                                  public interface::XFDispatcher
{
public:
    XFDispatcherActiveDefault();
    virtual ~XFDispatcherActiveDefault();

    virtual bool isActive() const { return (_pThread != nullptr) ? true : false; }

    virtual void start();
    virtual void stop();
    virtual void pushEvent(XFEvent * pEvent);

    virtual void scheduleTimeout(int timeoutId, int interval, interface::XFReactive * pReactive);
    virtual void unscheduleTimeout(int timeoutId, interface::XFReactive * pReactive);

    virtual int executeOnce();

protected:
    virtual int execute(const void * param = nullptr);
    virtual void dispatchEvent(const XFEvent * pEvent) const;

protected:
    bool _bExecuting;                   ///< True as long as the thread is executing the main loop.
    interface::XFThread * _pThread;     ///< Pointer to Thread executing the dispatcher.
    XFEventQueuePort _events;           ///< Thread-safe queue holding events waiting to get dispatched.
};

/** @} */ // end of port_default group
#endif // USE_XF_DISPATCHER_ACTIVE_DEFAULT_IMPLEMENTATION
#endif // XF_DISPATCHER_ACTIVE_H
