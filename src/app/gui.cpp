#include <string.h>
#include <assert.h>
#include "trace/trace.h"
#include "ui-gen/resources_manager.h"
#include "ui-gen/gui.h"
#include "gui.h"

#define TOUCH_THREAD_STACK_SIZE     2048

namespace oscilloscope {

GListener gl;

Gui::Gui() :
    _pGuiObserver(nullptr),
    _redLedOn(false),
    _xAxisPixelsPerField(0)
{

}

void Gui::initialize()
{
    // Initialize the uGFX library
    gfxInit();

    // Initialize the display
    guiInit();
    guiShowPage(DP_OSCILLOSCOPE);

    // Some custom drawing options
    {
        // Set title background
        gwinSetBgColor(ghLabelTitle, RGB2COLOR(12, 12, 12));
        gwinClear(ghLabelTitle);

        _xAxisPixelsPerField = gwinGetWidth(ghGraph) / observer().getTDivCount();
        GGraphStyle graphStyle = {
            { GGRAPH_POINT_DOT, 3, GFX_WHITE },                         // Point
            { GGRAPH_LINE_NONE, 1, GFX_WHITE },                         // Line (change to GGRAPH_LINE_SOLIDE to show it)
            { GGRAPH_LINE_NONE, 0, GFX_BLACK },                         // X axis
            { GGRAPH_LINE_NONE, 0, GFX_BLACK },                         // Y axis
            { GGRAPH_LINE_DASH, 4, GFX_GRAY, _xAxisPixelsPerField },    // X grid
            { GGRAPH_LINE_NONE, 0, GFX_GRAY, 50 },                      // Y grid
            GWIN_GRAPH_STYLE_POSITIVE_AXIS_ARROWS                       // Flags
        };

        // Set graph style
        gwinSetBgColor(ghGraph, RGB2COLOR(100, 100, 100));
        gwinClear(ghGraph);
        gwinGraphSetStyle(ghGraph, &graphStyle);

        // Disable red LED
        setRedLed(false);
    }

    // We want to listen for widget events
    geventListenerInit(&gl);
    gwinAttachListener(&gl);
}

bool Gui::registerObserver(interface::GuiObserver * pGuiObserver)
{
    if (!_pGuiObserver and pGuiObserver)
    {
        _pGuiObserver = pGuiObserver;
        return true;
    }
    return false;
}

void Gui::start()
{
    createTouchThread();

    startBehavior();
}

void Gui::drawGraphPoints(uint16_t * values, uint16_t count, float xScale /* = 1 */)
{
    const coord_t Y_SPACE = 4;      // Keep a little space left on top and bottom
    const coord_t MAX_WIDTH = gwinGetWidth(ghGraph);
    const coord_t MAX_HEIGHT = gwinGetHeight(ghGraph) - (2 * Y_SPACE);

    if (ghGraph)
    {
        uint32_t MAX = count;

        point * const points = (point *)gfxAlloc(sizeof(point) * MAX);

        if (points)
        {
            gwinClear(ghGraph);

            // Draw grid
            gwinGraphDrawAxis(ghGraph);
            gwinGraphStartSet(ghGraph);

            // Push values into point array
            for (uint32_t i = 0; i < MAX; i++)
            {
                points[i].x = i * xScale;
                points[i].y = values[i] * MAX_HEIGHT / 4096;      // Scaling
                points[i].y += Y_SPACE;                           // y axis offset
                //points[i].y = 0.5*i;                            // Generate fake data

                // Check if we run out of boundaries
                if (points[i].x > MAX_WIDTH)
                {
                    MAX = i;    // Adjust amount of points to draw
                    break;
                }
            }

            // Draw signal values
            gwinGraphDrawPoints(ghGraph, points, MAX);

            gfxFree(points);
        }
    }
}

bool Gui::isRedLedEnabled() const
{
    return _redLedOn;
}

void Gui::setRedLed(bool enable)
{
    _redLedOn = enable;

    if (enable)
    {
        gwinImageOpenFile(ghRedLed, gstudioGetImageFilePath(ledredon));
    }
    else
    {
        gwinImageOpenFile(ghRedLed, gstudioGetImageFilePath(ledredoff));
    }
}

bool Gui::isOscilloscopePageEnabled() const
{
    return gwinGetVisible(ghPageContainerDp_oscilloscope);
}

void Gui::setTimeDivisionText(std::string text)
{
    gwinSetText(ghLabelTimeDiv, text.c_str(), true);
}

XFEventStatus Gui::processEvent()
{
#if (PORT_IDF_STM32CUBE != 0)
    GEN(XFNullTransition);
    gfxYield();                   // Switch to next thread
#endif
    return XFEventStatus::Consumed;
}

static DECLARE_THREAD_STACK(touchThread, TOUCH_THREAD_STACK_SIZE);
DECLARE_THREAD_FUNCTION(touchThreadHandler, arg)
{
    GEvent * pe;
    Gui & gui = *(Gui *)arg;

    while (TRUE)
    {
        pe = geventEventWait(&gl, TIME_INFINITE);

        assert(pe);     // May indicate that thread stack is too small!
        switch(pe->type)
        {
        case GEVENT_GWIN_BUTTON:
            {
                GHandle buttonHandle = ((GEventGWinButton*)pe)->gwin;

                if (buttonHandle == ghPushButtonTrigger)
                {
                    Trace::out("Trigger button pressed");
                    gui.setRedLed(!gui.isRedLedEnabled());
                }
                else if (buttonHandle == ghPushButtonTimePlus)
                {
                    gui.onButtonTimePlusPressed();
                }
                else if (buttonHandle == ghPushButtonTimeMinus)
                {
                    gui.onButtonTimeMinusPressed();
                }
            }
            break;
        case GEVENT_GWIN_RADIO:
            {
                GHandle radioHandle = ((GEventGWinRadio*)pe)->gwin;

                if (radioHandle == ghRadiobuttonPwmLow)
                {
                    gui.onButtonPwmLowPressed();
                }
                else if (radioHandle == ghRadiobuttonPwmHigh)
                {
                    gui.onButtonPwmHighPressed();
                }
            }
            break;
        default:
            break;
        }
    }

#if (GFX_USE_OS_RAW32 != GFXOFF)
    return 0;
#endif // GFX_USE_OS_RAW32
}

void Gui::createTouchThread()
{
    gfxThreadCreate(touchThread, TOUCH_THREAD_STACK_SIZE, 3 /*makeFreeRtosPriority(osPriorityNormal)*/, &touchThreadHandler, this);
}

void Gui::onButtonTimePlusPressed()
{
    _pGuiObserver->onButtonTimePlusPressed();
}

void Gui::onButtonTimeMinusPressed()
{
    _pGuiObserver->onButtonTimeMinusPressed();
}

void Gui::onButtonPwmLowPressed()
{
    _pGuiObserver->onButtonPwmLowPressed();
}

void Gui::onButtonPwmHighPressed()
{
    _pGuiObserver->onButtonPwmHighPressed();
}

}   // namespace oscilloscope
