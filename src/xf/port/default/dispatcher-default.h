#ifndef XF_DISPATCHER_DEFAULT_H
#define XF_DISPATCHER_DEFAULT_H

#include <config/xf-config.h>

#if (USE_XF_DISPATCHER_DEFAULT_IMPLEMENTATION != 0)

#include "xf/interface/dispatcher.h"
#include "xf/interface/mutex.h"

/*
 * Please include the XFEventQueueDefault class in the xf-config file!
 * Example: #include "default/eventqueue-default.h"
 * and
 * define the XFEventQueueDefault class as the class representing the
 * XFEventQueue used by the dispatcher.
 * Example: using XFEventQueue = XFEventQueueDefault;
 *
 * In case you want to provide you own event queue, you must implement
 * your own XFEventQueue class and include the header file in the xf-config file.
 */

/** @ingroup port_default
 *  @{
 */
 
/**
 * @brief A dispatcher implementation which can be used without an OS.
 *
 * The dispatcher can be used when an IDF on a bare-metal embedded system is needed.
 */
class XFDispatcherDefault : public interface::XFDispatcher
{
public:
	XFDispatcherDefault();
	virtual  ~XFDispatcherDefault();

	virtual bool isActive() const { return false; }		///< Default dispatcher does not have a composite thread.

	virtual void start();
	virtual void stop();
	virtual void pushEvent(XFEvent * pEvent);

	virtual void scheduleTimeout(int timeoutId, int interval, interface::XFReactive * pReactive);
	virtual void unscheduleTimeout(int timeoutId, interface::XFReactive * pReactive);

	virtual int executeOnce();
	virtual int execute(const void * param = nullptr);

protected:
	virtual void dispatchEvent(const XFEvent * pEvent) const;

protected:
    bool _bExecuting;					///< True as long as the thread is executing the main loop.
    XFEventQueue _events;               ///< Queue holding events waiting to get dispatched.
    interface::XFMutex * _pMutex;		///< Mutex to protect event queue.
};

/** @} */ // end of port_default group
#endif // USE_XF_DISPATCHER_DEFAULT_IMPLEMENTATION
#endif // XF_DISPATCHER_DEFAULT_H
