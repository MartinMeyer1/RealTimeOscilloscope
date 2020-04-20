#include "xf/nulltransition.h"

XFNullTransition::XFNullTransition(interface::XFReactive * pBehavior)
 : XFEvent(XFEvent::NullTransition, 0, pBehavior)
{
}

bool XFNullTransition::deleteAfterConsume() const
{
    return true;
}
