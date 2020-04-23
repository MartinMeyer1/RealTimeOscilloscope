#ifndef INTERFACE_BUTTONS_CONTROLLER_CALLBACK_CALLER_H
#define INTERFACE_BUTTONS_CONTROLLER_CALLBACK_CALLER_H

#include "buttonscontrollercallbackprovider.h"

namespace interface {

/**
 * @brief Interface to be provided by the ButtonsController.
 *
 */
class ButtonsControllerCallbackCaller
{
protected:
    virtual ~ButtonsControllerCallbackCaller() {}

    /**
     * @brief Registers a callback method with its called pointer (callback provider).
     *
     * @return Returns true of the callback provider could be registered, otherwise false.
     */
    virtual bool registerCallback(ButtonsControllerCallbackProvider * callbackProvider,
                                  ButtonsControllerCallbackProvider::CallbackMethod callbackMethod) = 0;

protected:
    ButtonsControllerCallbackCaller() {}                        ///< Not allowing to instantiate object of interface.
};

} // namespace interface
#endif // INTERFACE_BUTTONS_CONTROLLER_CALLBACK_CALLER_H
