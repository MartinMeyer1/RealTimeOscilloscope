#include <assert.h>
#include "trace/trace.h"
#include "xf/eventstatus.h"
#include "main.h"
#include "gui.h"
#include "sig-gen/pwmgenerator.h"
#include "oscilloscopecontroller.h"

OscilloscopeController * OscilloscopeController::_pInstance(nullptr);

const oscilloscope::TDivOption OscilloscopeController::_tdivOptions[] = {{oscilloscope::TDIV_500us, "500 us / div"},
                                                                         {oscilloscope::TDIV_1ms,     "1 ms / div"},
                                                                         {oscilloscope::TDIV_2ms,     "2 ms / div"},
                                                                         {oscilloscope::TDIV_5ms,     "5 ms / div"},
                                                                         {oscilloscope::TDIV_10ms,   "10 ms / div"}};

OscilloscopeController::OscilloscopeController() :
    _pGui(nullptr),
    _adcValuesBuffer(nullptr),
	_adcValuesBufferSize(0),
	_tdivValue(oscilloscope::TDIV_1ms)
{
    assert(!_pInstance);    // Only one instance of this class allowed!
    _pInstance = this;
}

//static
OscilloscopeController & OscilloscopeController::getInstance()
{
    assert(_pInstance);     // Create first an instance!
    return *_pInstance;
}

void OscilloscopeController::initialize(oscilloscope::Gui & gui, uint16_t * adcValuesBuffer, uint32_t adcValuesBufferSize)
{
    _pGui = &gui;
    _adcValuesBuffer = adcValuesBuffer;
    _adcValuesBufferSize = adcValuesBufferSize;

    gui.registerObserver(this);     // Get notified about GUI events
}

void OscilloscopeController::start()
{
    startBehavior();
}

XFEventStatus OscilloscopeController::processEvent()
{
    assert(_adcValuesBuffer);
    assert(_adcValuesBufferSize > 0);

	if (getCurrentEvent()->getEventType() == XFEvent::Initial)
	{
		scheduleTimeout(TIMEOUT_ID, TIMEOUT_INTERVAL);

		doShowAnalogSignal();
	}

	if (getCurrentEvent()->getEventType() == XFEvent::Timeout &&
		getCurrentTimeout()->getId() == TIMEOUT_ID)
	{
		scheduleTimeout(TIMEOUT_ID, TIMEOUT_INTERVAL);

		doShowAnalogSignal();
	}

	return XFEventStatus::Consumed;
}

void OscilloscopeController::onButtonTimePlusPressed()
{
    if (_tdivValue < (oscilloscope::TDIV_MAX - 1))
    {
        _tdivValue = (oscilloscope::TDivValue)(_tdivValue + 1);

        gui().setTimeDivisionText(getText(_tdivValue));
    }
}

void OscilloscopeController::onButtonTimeMinusPressed()
{
    if (_tdivValue > (oscilloscope::TDIV_MIN + 1))
    {
        _tdivValue = (oscilloscope::TDivValue)(_tdivValue - 1);

        gui().setTimeDivisionText(getText(_tdivValue));
    }
}

void OscilloscopeController::onButtonPwmLowPressed()
{
#if defined(ENABLE_SIGGEN_PWMGENERATOR) && (ENABLE_SIGGEN_PWMGENERATOR != 0)
    siggen::PwmGenerator::getInstance().setFrequency(50 /*[Hz]*/);
#endif // ENABLE_SIGGEN_PWMGENERATOR
}

void OscilloscopeController::onButtonPwmHighPressed()
{
#if defined(ENABLE_SIGGEN_PWMGENERATOR) && (ENABLE_SIGGEN_PWMGENERATOR != 0)
    siggen::PwmGenerator::getInstance().setFrequency(1e3 /*[Hz]*/);
#endif // ENABLE_SIGGEN_PWMGENERATOR
}


void OscilloscopeController::doShowAnalogSignal()
{
	float xScale;
	//x = 640px
	//tech = 100us
	//8 div
	//80 px/div
	//2*(tech*divpx/tDiv)


	switch(_tdivValue){
	case oscilloscope::TDIV_500us:
			xScale=32;
		break;
	case oscilloscope::TDIV_1ms:
			xScale=16;
		break;
	case oscilloscope::TDIV_2ms:
			xScale=8;
		break;
	case oscilloscope::TDIV_5ms:
			xScale=3.2;
		break;
	case oscilloscope::TDIV_10ms:
			xScale=1.6;
		break;
	default:
		break;
	}
	gui().drawGraphPoints(_adcValuesBuffer, _adcValuesBufferSize,xScale);
}

std::string OscilloscopeController::getText(oscilloscope::TDivValue tdivValue)
{
    const uint32_t count = sizeof(_tdivOptions)/sizeof(_tdivOptions[0]);

    for (uint32_t i = 0; i < count; i++)
    {
        if (_tdivOptions[i].tdivValue == tdivValue)
        {
            return _tdivOptions[i].text;
        }
    }
    return "n/a";
}
