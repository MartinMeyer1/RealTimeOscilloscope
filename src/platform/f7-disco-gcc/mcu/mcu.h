#ifndef MCU_STM32F7_MCU_H
#define MCU_STM32F7_MCU_H

#include "stm32f7xx_hal.h"
#include "trace/trace.h"

class Mcu
{
public:
    inline static void msleep(uint32_t msecs) { HAL_Delay(msecs); }
    inline static void wait() { for (uint32_t i = 1000000; i > 0; i--) continue; }
    static void reset()
    {
        Trace::out("Mcu: Reset");
        Trace::out("----------------------------------------------------");
        wait();
        NVIC_SystemReset();
    }
};

#endif // MCU_STM32F7_MCU_H
