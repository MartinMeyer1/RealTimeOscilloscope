#include <config/xf-config.h>

#if (USE_XF_PORT_IDF_STM32CUBE_PORT_FUNCTIONS_IMPLEMENTATION != 0)

#include <assert.h>
#include "mcu/mcu.h"
#include "critical/critical.h"
#include "xf/interface/timeoutmanager.h"
#include "xf/port/port-functions.h"

using interface::XFTimeoutManager;

/**
 * For this port the following port functions need to be implemented:
 *  - XF_startTimeoutManagerTimer()
 *  - XF_tick()
 *  - XF_tickIntervalInMilliseconds()
 
 * In the XF_startTimeoutManagerTimer() function no code needs to
 * be implemented because the SysTick peripheral is already initialized
 * be the STM32CubeMX HAL. 
 * This means that changes in 'tickInterval' needs to be handled elsewhere
 * using the XF_tickIntervalInMilliseconds() function.
 */

void XF_startTimeoutManagerTimer(uint32_t tickInterval)
{
    (void)tickInterval;

    // SysTick gets already started by the STM32CubeMX HAL.
    // So nothing to do here.
}

/**
 * SysTick_Handler() function is already implemented in the STM32CubeMX generated
 * code (see Src/stm32fxxx_it.c file). Therefore, we must provide here a function
 * which can be explicitly called in SysTick_Handler() to tick the XF.
 */
void XF_tick()
{
	bInISR = true;								// Tell critical section we are in an ISR
	XFTimeoutManager::getInstance()->tick();    // Call framework hook tick function
	bInISR = false;
}

/**
 * C function wrapping getTickInterval() method of XFTimeoutManager.
 */
int32_t XF_tickIntervalInMilliseconds()
{
    return XFTimeoutManager::getInstance()->getTickInterval();
}

#endif // USE_XF_PORT_IDF_STM32CUBE_PORT_FUNCTIONS_IMPLEMENTATION
