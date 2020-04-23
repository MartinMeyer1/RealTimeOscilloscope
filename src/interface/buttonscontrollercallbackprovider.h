#ifndef INTERFACE_BUTTONS_CONTROLLER_CALLBACK_PROVIDER_H
#define INTERFACE_BUTTONS_CONTROLLER_CALLBACK_PROVIDER_H

#include <stdint.h>

namespace interface {

/**
 * @brief Interface needed by the ButtonsController to notify a method callback provider.
 *
 */
class ButtonsControllerCallbackProvider
{
public:
    virtual ~ButtonsControllerCallbackProvider() {}

    /**
     * @brief The method prototype of the callback method to be provided by the class implementing the interface.
     *
     * Example implementation:
     *   // Called by ButtonsController to notify button pressed/released events.
     *   void onButtonChanged(uint16_t buttonIndex, bool pressed);
     *
     */
    typedef void (ButtonsControllerCallbackProvider::*CallbackMethod)(uint16_t buttonIndex, bool pressed);

protected:
    ButtonsControllerCallbackProvider() {}                                  ///< Not allowing to instantiate object of interface.
};

} // namespace interface
#endif // INTERFACE_BUTTONS_CONTROLLER_CALLBACK_H
