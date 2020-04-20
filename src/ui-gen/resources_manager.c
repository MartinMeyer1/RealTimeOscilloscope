#include "resources_manager.h"

typedef struct ImageInfo {
	gdispImage* pointer;
	const char* filePath;
} ImageInfo;

gdispImage imgledredoff;
gdispImage imgledredon;

static ImageInfo _imagesArray[2];
static font_t _fontsArray[2];

bool_t guiResourcesManagerInit(void)
{
	size_t i;

	// Fill images array
	_imagesArray[0].pointer = &imgledredoff;
	_imagesArray[0].filePath = "red_led_circle_02.png";
	_imagesArray[1].pointer = &imgledredon;
	_imagesArray[1].filePath = "red_led_circle_01.png";

	// Open images
	for (i = 0; i < 2; i++) {
		gdispImageOpenFile(gstudioGetImage(i), gstudioGetImageFilePath(i));
	}

	// Cache images
	gdispImageCache(gstudioGetImage(0));
	gdispImageCache(gstudioGetImage(1));

	// Open fonts
	_fontsArray[0] = gdispOpenFont("dejavusans18_bold_dejavusans_bold18_aa");
	_fontsArray[1] = gdispOpenFont("dejavusans12_dejavusans12_aa");

	return TRUE;
}

GFXINLINE gdispImage* gstudioGetImage(int imageIndex)
{
	return _imagesArray[imageIndex].pointer;
}

GFXINLINE const char* gstudioGetImageFilePath(int imageIndex)
{
	return _imagesArray[imageIndex].filePath;
}

GFXINLINE font_t gstudioGetFont(int fontIndex)
{
	return _fontsArray[fontIndex];
}

