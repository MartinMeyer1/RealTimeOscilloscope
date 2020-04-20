#include "gui.h"
#include "rendering_functions.h"
#include "widgetstyles.h"
#include "resources_manager.h"

GHandle ghPageContainerDp_oscilloscope;
GHandle ghPushButtonTimePlus;
GHandle ghPushButtonTimeMinus;
GHandle ghRedLed;
GHandle ghLabelTitle;
GHandle ghPushButtonTrigger;
GHandle ghLabelTimeDiv;
GHandle ghGraph;
GHandle ghRadiobuttonPwmHigh;
GHandle ghLabel;
GHandle ghRadiobuttonPwmLow;

static bool_t _createPagedp_oscilloscope(void)
{
	GWidgetInit wi;

	gwinWidgetClearInit(&wi);

	// Page container
	wi.g.show = FALSE;
	wi.g.x = 0;
	wi.g.y = 0;
	wi.g.width = 480;
	wi.g.height = 272;
	wi.g.parent = 0;
	wi.text = "Container";
	wi.customDraw = background_Display_Background;
	wi.customParam = 0;
	wi.customStyle = 0;
	ghPageContainerDp_oscilloscope = gwinContainerCreate(0, &wi, GWIN_CONTAINER_BORDER);

	// ghPushButtonTimePlus
	wi.g.show = TRUE;
	wi.g.x = 435;
	wi.g.y = 230;
	wi.g.width = 38;
	wi.g.height = 36;
	wi.g.parent = ghPageContainerDp_oscilloscope;
	wi.text = "+";
	wi.customDraw = 0;
	wi.customParam = 0;
	wi.customStyle = 0;
	ghPushButtonTimePlus = gwinButtonCreate(0, &wi);
	gwinSetFont(ghPushButtonTimePlus, gstudioGetFont(DejaVuSans18Bold));

	// ghPushButtonTimeMinus
	wi.g.show = TRUE;
	wi.g.x = 387;
	wi.g.y = 230;
	wi.g.width = 40;
	wi.g.height = 36;
	wi.g.parent = ghPageContainerDp_oscilloscope;
	wi.text = "-";
	wi.customDraw = 0;
	wi.customParam = 0;
	wi.customStyle = 0;
	ghPushButtonTimeMinus = gwinButtonCreate(0, &wi);
	gwinSetFont(ghPushButtonTimeMinus, gstudioGetFont(DejaVuSans18Bold));

	// ghRedLed
	wi.g.show = TRUE;
	wi.g.x = 94;
	wi.g.y = 240;
	wi.g.width = 18;
	wi.g.height = 18;
	wi.g.parent = ghPageContainerDp_oscilloscope;
	wi.text = "";
	wi.customDraw = 0;
	wi.customParam = 0;
	wi.customStyle = 0;
	ghRedLed = gwinImageCreate(0, &wi.g);
	gwinImageOpenFile(ghRedLed, gstudioGetImageFilePath(ledredoff));

	// ghLabelTitle
	wi.g.show = TRUE;
	wi.g.x = 7;
	wi.g.y = 5;
	wi.g.width = 467;
	wi.g.height = 30;
	wi.g.parent = ghPageContainerDp_oscilloscope;
	wi.text = "REALTIME OSCILLOSCOPE";
	wi.customDraw = 0;
	wi.customParam = 0;
	wi.customStyle = 0;
	ghLabelTitle = gwinLabelCreate(0, &wi);
	gwinSetFont(ghLabelTitle, gstudioGetFont(DejaVuSans12));

	// ghPushButtonTrigger
	wi.g.show = TRUE;
	wi.g.x = 10;
	wi.g.y = 230;
	wi.g.width = 75;
	wi.g.height = 36;
	wi.g.parent = ghPageContainerDp_oscilloscope;
	wi.text = "Trigger";
	wi.customDraw = 0;
	wi.customParam = 0;
	wi.customStyle = 0;
	ghPushButtonTrigger = gwinButtonCreate(0, &wi);

	// ghLabelTimeDiv
	wi.g.show = TRUE;
	wi.g.x = 302;
	wi.g.y = 233;
	wi.g.width = 81;
	wi.g.height = 30;
	wi.g.parent = ghPageContainerDp_oscilloscope;
	wi.text = "1 ms / div";
	wi.customDraw = gwinLabelDrawJustifiedRight;
	wi.customParam = 0;
	wi.customStyle = 0;
	ghLabelTimeDiv = gwinLabelCreate(0, &wi);
	gwinSetFont(ghLabelTimeDiv, gstudioGetFont(DejaVuSans12));

	// ghGraph
	wi.g.show = TRUE;
	wi.g.x = 12;
	wi.g.y = 36;
	wi.g.width = 448;
	wi.g.height = 188;
	wi.g.parent = ghPageContainerDp_oscilloscope;
	ghGraph = gwinGraphCreate(0, &wi.g);

	// ghRadiobuttonPwmHigh
	wi.g.show = TRUE;
	wi.g.x = 243;
	wi.g.y = 235;
	wi.g.width = 55;
	wi.g.height = 30;
	wi.g.parent = ghPageContainerDp_oscilloscope;
	wi.text = "1 kHz";
	wi.customDraw = gwinRadioDraw_Tab;
	wi.customParam = 0;
	wi.customStyle = &PWM_Gen;
	ghRadiobuttonPwmHigh = gwinRadioCreate(0, &wi, 0);

	// ghLabel
	wi.g.show = TRUE;
	wi.g.x = 124;
	wi.g.y = 235;
	wi.g.width = 64;
	wi.g.height = 30;
	wi.g.parent = ghPageContainerDp_oscilloscope;
	wi.text = "PWM Gen:";
	wi.customDraw = 0;
	wi.customParam = 0;
	wi.customStyle = &PWM_Gen;
	ghLabel = gwinLabelCreate(0, &wi);

	// ghRadiobuttonPwmLow
	wi.g.show = TRUE;
	wi.g.x = 188;
	wi.g.y = 235;
	wi.g.width = 55;
	wi.g.height = 30;
	wi.g.parent = ghPageContainerDp_oscilloscope;
	wi.text = "50 Hz";
	wi.customDraw = gwinRadioDraw_Tab;
	wi.customParam = 0;
	wi.customStyle = &PWM_Gen;
	ghRadiobuttonPwmLow = gwinRadioCreate(0, &wi, 0);
	gwinRadioPress(ghRadiobuttonPwmLow);

	return TRUE;
}

void guiShowPage(guiPage page)
{
	// Hide all pages
	gwinHide(ghPageContainerDp_oscilloscope);

	// Show the selected page
	switch (page) {
		case DP_OSCILLOSCOPE:
			gwinShow(ghPageContainerDp_oscilloscope);
			break;

		default:
			break;
	}
}

bool_t guiInit(void)
{
	// Initialize resources
	if (!guiResourcesManagerInit()) {
		return FALSE;
	}

	// Set GWIN default values
	gwinSetDefaultStyle(&WhiteWidgetStyle, FALSE);
	gwinSetDefaultFont(gstudioGetFont(DejaVuSans12));

	// Create display pages
	_createPagedp_oscilloscope();

	return TRUE;
}

