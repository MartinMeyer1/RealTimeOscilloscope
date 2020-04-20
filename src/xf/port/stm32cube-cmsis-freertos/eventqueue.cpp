#include <config/xf-config.h>

#if (USE_XF_PORT_STM32CUBE_CMSIS_FREERTOS_EVENT_QUEUE_IMPLEMENTATION != 0)

#include <assert.h>
#include "eventqueue.h"

XFEventQueuePort::XFEventQueuePort(const uint32_t queueSize /* = 8 */)
{
	_queueDefinition.item_sz = sizeof(XFEvent *);
	_queueDefinition.queue_sz = queueSize;

	_queueId = osMessageCreate(&_queueDefinition, nullptr);
	assert(_queueId);
}

XFEventQueuePort::~XFEventQueuePort()
{
	osMessageDelete(_queueId);
}

bool XFEventQueuePort::empty() const
{
	return (osMessageWaiting(_queueId) == 0);
}

bool XFEventQueuePort::push(const XFEvent * pEvent)
{
	const osStatus status = osMessagePut(_queueId, (uint32_t)pEvent, 100);
	return (status == osOK);
}

XFEvent * XFEventQueuePort::front()
{
	XFEvent * popedEvent = nullptr;

	assert(!empty());

	const osEvent status = osMessagePeek(_queueId, 100);

	if (status.status == osEventMessage)
	{
		popedEvent = (XFEvent *)status.value.p;
	}

	return popedEvent;
}

void XFEventQueuePort::pop()
{
	assert(!empty());

	auto osevent = osMessageGet(_queueId, 100);
	assert(osevent.status == osEventMessage);
}

bool XFEventQueuePort::pend()
{
	const osEvent status = osMessagePeek(_queueId, 0xFFFFFFFFL);

	return (status.status == osEventMessage);
}

#endif // USE_XF_PORT_STM32CUBE_CMSIS_FREERTOS_EVENT_QUEUE_IMPLEMENTATION
