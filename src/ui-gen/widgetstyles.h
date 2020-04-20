#ifndef _WIDGETSTYLES_H
#define _WIDGETSTYLES_H

#include "gfx.h"

// WidgetStyle: PWM_Gen
const GWidgetStyle PWM_Gen = {
	HTML2COLOR(0x2D9DDD),              // background
	HTML2COLOR(0x34B8FF),              // focus

	// Enabled color set
	{
		HTML2COLOR(0x000000),         // text
		HTML2COLOR(0xA2A2A2),         // edge
		HTML2COLOR(0x2D9DDD),         // fill
		HTML2COLOR(0x00E000)          // progress (active area)
	},

	// Disabled color set
	{
		HTML2COLOR(0xC0C0C0),         // text
		HTML2COLOR(0x808080),         // edge
		HTML2COLOR(0xE0E0E0),         // fill
		HTML2COLOR(0xC0E0C0)          // progress (active area)
	},

	// Pressed color set
	{
		HTML2COLOR(0x000000),         // text
		HTML2COLOR(0x000000),         // edge
		HTML2COLOR(0x2D9DDD),         // fill
		HTML2COLOR(0x00E000)          // progress (active area)
	}
};

// WidgetStyle: Widget Style
const GWidgetStyle Widget_Style = {
	HTML2COLOR(0xFFFFFF),              // background
	HTML2COLOR(0x2A8FCD),              // focus

	// Enabled color set
	{
		HTML2COLOR(0x000000),         // text
		HTML2COLOR(0x404040),         // edge
		HTML2COLOR(0xE0E0E0),         // fill
		HTML2COLOR(0x00E000)          // progress (active area)
	},

	// Disabled color set
	{
		HTML2COLOR(0xC0C0C0),         // text
		HTML2COLOR(0x808080),         // edge
		HTML2COLOR(0xE0E0E0),         // fill
		HTML2COLOR(0xC0E0C0)          // progress (active area)
	},

	// Pressed color set
	{
		HTML2COLOR(0x404040),         // text
		HTML2COLOR(0x404040),         // edge
		HTML2COLOR(0x808080),         // fill
		HTML2COLOR(0x00E000)          // progress (active area)
	}
};

#endif // _WIDGETSTYLES_H
