#ifndef _RENDERING_FUNCTIONS_H
#define _RENDERING_FUNCTIONS_H

#include "gfx.h"
#include "resources_manager.h"

#ifndef White
    #define White GFX_WHITE
#endif

// background_Display Background
void background_Display_Background(GWidgetObject* wo, void* param)
{
	(void)param;

	gdispGFillArea(wo->g.display, wo->g.x, wo->g.y, wo->g.width, wo->g.height, White);
}

#endif // _RENDERING_FUNCTIONS_H
