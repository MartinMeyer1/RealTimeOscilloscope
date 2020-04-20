#include <assert.h>
#include "xf/xf.h"
#include "xf/interface/resourcefactory.h"
#include "xf/interface/dispatcher.h"
#include "xf/timeout.h"
#include "xf/initialevent.h"
#include "xf/behavior.h"

using interface::XFResourceFactory;

XFBehavior::XFBehavior(bool ownDispatcher /* = false */) :
    _pDispatcher(nullptr),
    _hasOwnDispatcher(ownDispatcher),
    deleteOnTerminate_(false),
    _pCurrentEvent(nullptr)
{
    if (ownDispatcher)
    {
        _pDispatcher = XFResourceFactory::getInstance()->createDispatcher();
    }
    else
    {
        _pDispatcher = XFResourceFactory::getInstance()->getDefaultDispatcher();
    }

    // Force hasOwnDispatcher attribute to false in case actual
    // dispatcher is the default dispatcher. This may happen
    // if in an IDF an other dispatcher is requested, but
    // only the default dispatcher is present.
    if (_pDispatcher == XFResourceFactory::getInstance()->getDefaultDispatcher())
    {
        _hasOwnDispatcher = false;
    }
}

XFBehavior::~XFBehavior()
{

}

void XFBehavior::startBehavior()
{
    // Send initial event to state machine
    GEN(XFInitialEvent());

    // Start dispatcher if behavior has its own dispatcher
    if (hasOwnDispatcher())
    {
        getDispatcher()->start();
    }
}

void XFBehavior::pushEvent(XFEvent * pEvent)
{
    // Set owner
    pEvent->setBehavior(this);
    // Push to dispatchers event queue
    getDispatcher()->pushEvent(pEvent);
}

bool XFBehavior::deleteOnTerminate() const
{
    return deleteOnTerminate_;
}

void XFBehavior::setDeleteOnTerminate(bool deleteBehaviour)
{
    deleteOnTerminate_ = deleteBehaviour;
}

XFBehavior::TerminateBehavior XFBehavior::process(const XFEvent * pEvent)
{
    XFEventStatus eventStatus;

    setCurrentEvent(pEvent);

    eventStatus = processEvent();

    setCurrentEvent(nullptr);

    return (eventStatus == XFEventStatus::Terminate);
}

interface::XFDispatcher * XFBehavior::getDispatcher()
{
    return _pDispatcher;
}

void XFBehavior::setCurrentEvent(const XFEvent * pEvent)
{
    _pCurrentEvent = pEvent;
}

const XFEvent * XFBehavior::getCurrentEvent() const
{
    return _pCurrentEvent;
}

const XFTimeout * XFBehavior::getCurrentTimeout()
{
    assert(getCurrentEvent()->getEventType() == XFEvent::Timeout);

    return static_cast<const XFTimeout *>(getCurrentEvent());
}
