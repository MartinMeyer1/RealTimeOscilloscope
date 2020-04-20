#ifndef XF_PORT_STM32CUBE_CMSIS_FREERTOS_EVENT_QUEUE_H
#define XF_PORT_STM32CUBE_CMSIS_FREERTOS_EVENT_QUEUE_H
#ifdef __cplusplus

#include <config/xf-config.h>

#if (USE_XF_PORT_STM32CUBE_CMSIS_FREERTOS_EVENT_QUEUE_IMPLEMENTATION != 0)

#include "xf/interface/eventqueue.h"
#include "cmsis_os.h"

class XFEventQueuePort : public interface::XFEventQueue
{
public:
	XFEventQueuePort(const uint32_t queueSize = 8);
	virtual ~XFEventQueuePort();

	// XFEventQueue interface implementation
public:
	virtual bool empty() const;
	virtual bool push(const XFEvent * pEvent);
	virtual XFEvent * front();
	virtual void pop();

	virtual bool pend();

protected:
	osMessageQDef_t _queueDefinition;		///< Event queue definition.
	osMessageQId _queueId;					///< Unique identifier of the queue.
};

#endif // USE_XF_PORT_STM32CUBE_CMSIS_FREERTOS_EVENT_QUEUE_IMPLEMENTATION
#endif // __cplusplus
#endif // XF_PORT_STM32CUBE_CMSIS_FREERTOS_EVENT_QUEUE_H
