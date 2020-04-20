#ifndef _GUI_H
#define _GUI_H

#include "gfx.h"

typedef enum guiPage {
	DP_OSCILLOSCOPE,
} guiPage;

// Widget handles
extern GHandle ghPageContainerDp_oscilloscope;
extern GHandle ghPushButtonTimePlus;
extern GHandle ghPushButtonTimeMinus;
extern GHandle ghRedLed;
extern GHandle ghLabelTitle;
extern GHandle ghPushButtonTrigger;
extern GHandle ghLabelTimeDiv;
extern GHandle ghGraph;
extern GHandle ghRadiobuttonPwmLow;
extern GHandle ghLabel;
extern GHandle ghRadiobuttonPwmHigh;

#ifdef __cplusplus
extern "C" {
#endif

	bool_t guiInit(void);
	void guiShowPage(guiPage page);

#ifdef __cplusplus
}
#endif

#endif // _GUI_H
