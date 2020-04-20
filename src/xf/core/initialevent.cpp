#include "xf/initialevent.h"

XFInitialEvent::XFInitialEvent()
    : XFEvent(XFEvent::Initial, 0, nullptr)
{
}

bool XFInitialEvent::deleteAfterConsume() const
{
    return true;
}
