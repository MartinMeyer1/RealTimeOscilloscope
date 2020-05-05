#ifndef OSCILLOSCOPECONTROLLER_H
#define OSCILLOSCOPECONTROLLER_H

#include <assert.h>
#include <string>
#include "xf/behavior.h"
#include "interface/guiobserver.h"

namespace oscilloscope {
    class Gui;

typedef enum
{
    TDIV_MIN = 0,
    TDIV_500us,
    TDIV_1ms,
    TDIV_2ms,
    TDIV_5ms,
    TDIV_10ms,
    TDIV_MAX
} TDivValue;

typedef struct
{
    TDivValue tdivValue;
    std::string text;
} TDivOption;

}   // namespace oscilloscope

/**
 * @brief The Oscilloscope Controller
 *
 * Responsible to provide and update oscilloscope data. All input
 * (touch screen, signal measurement data) comes to the controller
 * and updates then the view(s) accordingly.
 */
class OscilloscopeController : public XFBehavior,
                               public interface::GuiObserver
{
public:
	OscilloscopeController();
	virtual ~OscilloscopeController() {}

	static OscilloscopeController & getInstance();

	void initialize(oscilloscope::Gui & gui, uint16_t * adcValuesBuffer, uint32_t adcValuesBufferSize);

	void start();

	inline oscilloscope::TDivValue getTDivValue() const { return _tdivValue; }

	// XFReactive interface implementation
protected:
	XFEventStatus processEvent() override;

	// GuiObserver interface implementation
protected:
    void onButtonTimePlusPressed() override;
    void onButtonTimeMinusPressed() override;
    void onButtonPwmLowPressed() override;
    void onButtonPwmHighPressed() override;
    void onButtonTriggerPressed()override;
    uint32_t getTDivCount() const override { return 8; };

protected:
	void doShowAnalogSignal();
	inline oscilloscope::Gui & gui() const { assert(_pGui); return *_pGui; }

	std::string getText(oscilloscope::TDivValue tdivValue);

protected:
	static OscilloscopeController * _pInstance;

	oscilloscope::Gui * _pGui;
	uint16_t * _adcValuesBuffer;
	uint32_t _adcValuesBufferSize;

	const int TIMEOUT_ID = 0;
	const int TIMEOUT_INTERVAL = 50;

	oscilloscope::TDivValue _tdivValue;

	bool TriggerOn;
	uint32_t triggerValue;
	uint32_t t;
	uint32_t f;
	static const oscilloscope::TDivOption _tdivOptions[];
};

#endif // OSCILLOSCOPECONTROLLER_H
