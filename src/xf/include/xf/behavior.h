#ifndef XF_BEHAVIOR_H
#define XF_BEHAVIOR_H

#include "xf/interface/reactive.h"
#include "xf/interface/dispatcher.h"
#include "xf/eventstatus.h"
#include "xf/initialevent.h"
#include "xf/nulltransition.h"
#include "xf/timeout.h"

class XFTimeout;

/** @ingroup xf_core
 *  @{
 */

/**
 * @brief Base class for state machines, activities, process and data flows.
 *
 * Reactive class implementing a behavior. This class can be used to
 * implement a state machine behavior or an activity behavior.
 *
 * Override the processEvent() operation in the inherited class to implement
 * your state machine behavior. The processEvent() method gets automatically
 * called every time an event or timeout arrives. The event (or timeout) can
 * be accessed via the getCurrentEvent() method.
 */
class XFBehavior : public interface::XFReactive
{
public:
    #define GEN(event) pushEvent(new event)

    /**
     * @brief Default constructor for the behavior.
     *
     * Per default the XFBehavior chooses the 'default dispatcher' for event processing. In
     * case the ownDispatcher parameter is set to true, the XFBehavior creates internally
     * a separate dispatcher.
     *
     * @param ownDispatcher Set to true to get dedicated dispatcher for this behavior.
     */
    explicit XFBehavior(bool ownDispatcher = false);
    virtual ~XFBehavior();

    virtual void startBehavior();					///< Starts the behavior, resp. the state machine.

    virtual void pushEvent(XFEvent * pEvent);

    bool deleteOnTerminate() const override;
    void setDeleteOnTerminate(bool deleteBehaviour) override;

protected:
    /**
     * Executes the current event in its implemented behavior.
     * This method needs to be overridden to implement the
     * behavior (i.e. state machine) needed.
     */
    virtual XFEventStatus processEvent() = 0;

    const XFEvent * getCurrentEvent() const;                            ///< Returns the current event to be processed in processEvent().
    interface::XFDispatcher * getDispatcher();                          ///< Returns reference to #_pDispatcher.
    inline bool hasOwnDispatcher() const { return _hasOwnDispatcher; }	///< True if behavior has its own dispatcher.


    /** \brief Returns a reference to the actually processed timeout.
     *
     * Will work only if the current event is of type IXFEvent::Timeout.
     */
    const XFTimeout * getCurrentTimeout();

    inline void scheduleTimeout(int timeoutId, int interval) { getDispatcher()->scheduleTimeout(timeoutId, interval, this); }	///< @brief Schedules a timeout for this state machine.
    inline void unscheduleTimeout(int timeoutId) { getDispatcher()->unscheduleTimeout(timeoutId, this); }						///< @brief Unschedules a timeout for this state machine.

private:
    void setCurrentEvent(const XFEvent * pEvent);		///< Sets the current event to be processed in processEvent().

    /**
     * \brief Processes the given event.
     *
     * The dispatcher calls this method every time a new event
     * or timeout arrives. The process method stores the actual
     * event using the #_pCurrentEvent and then calls
     * processEvent().
     *
     * In case you intend to call process() inside your state machine you
     * are doing something wrong! Call GEN() or pushEvent() instead!
     *
     * \param pEvent The event to process.
     */
    virtual TerminateBehavior process(const XFEvent * pEvent);


protected:
    interface::XFDispatcher * _pDispatcher;			///< Reference to dispatcher processing this behavior.
    bool _hasOwnDispatcher;							///< True if behavior has its own dispatcher, False if the default dispatcher is used.
    bool deleteOnTerminate_;                        ///< Indicates if the behavior can be deleted after reception of a 'terminate event'.
    const XFEvent * _pCurrentEvent;					///< Reference to actually processed event.
};

/** @} */ // end of xf_core group
#endif // XF_BEHAVIOR_H
