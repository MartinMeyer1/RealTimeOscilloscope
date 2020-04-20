#include <config/xf-config.h>

#if (USE_XF_EVENT_QUEUE_DEFAULT_IDF_IMPLEMENTATION != 0)

#include <assert.h>
#include "eventqueue-default.h"

XFEventQueueDefault::XFEventQueueDefault()
{

}

XFEventQueueDefault::~XFEventQueueDefault()
{

}

bool XFEventQueueDefault::empty() const
{
    return _queue.empty();
}

bool XFEventQueueDefault::push(const XFEvent * pEvent)
{
    _mutex.lock();
    {
        _queue.push(pEvent);
    }
    _mutex.unlock();

    return true;
}

const XFEvent * XFEventQueueDefault::front()
{
    const XFEvent * event;
    _mutex.lock();
    {
        event =  _queue.front();
    }
    _mutex.unlock();
    return event;
}

void XFEventQueueDefault::pop()
{
    _mutex.lock();
    {
        _queue.pop();
    }
    _mutex.unlock();
}

bool XFEventQueueDefault::pend()
{
    // Method cannot be used in an IDF! Waiting within
    // this method would block the whole XF
    return false;
}

#endif // USE_XF_EVENT_QUEUE_DEFAULT_IDF_IMPLEMENTATION
