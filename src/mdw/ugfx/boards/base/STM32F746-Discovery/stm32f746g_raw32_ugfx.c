#include "../../../gfx.h"
#if GFX_COMPAT_V2 && GFX_COMPAT_OLDCOLORS
	#undef Red
	#undef Green
	#undef Blue
#endif
#include "stm32f7xx_hal.h"

#if GFX_USE_OS_CHIBIOS
	#define HAL_GPIO_Init(port, ptr)	palSetGroupMode(port, (ptr)->Pin, 0, (ptr)->Mode|((ptr)->Speed<<3)|((ptr)->Pull<<5)|((ptr)->Alternate<<7))
#elif (GFX_USE_OS_RAW32 != GFXOFF)
	systemticks_t gfxSystemTicks(void)
	{
		return HAL_GetTick();
	}

	systemticks_t gfxMillisecondsToTicks(delaytime_t ms)
	{
		return ms;
	}
#endif // GFX_USE_OS_RAW32

#if (GFX_USE_OS_RAW32 != GFXOFF)
void Raw32OSInit(void)
{
    /* Enable the CPU Cache's */
	SCB_EnableICache();	// Enable I-Cache
	SCB_EnableDCache();	// Enable D-Cache
}
#endif // GFX_USE_OS_RAW32
