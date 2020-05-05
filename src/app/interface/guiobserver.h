#ifndef INTERFACE_GUI_OBSERVER_H
#define INTERFACE_GUI_OBSERVER_H

namespace interface {

class GuiObserver
{
public:
    virtual ~GuiObserver() {}

    virtual void onButtonTimePlusPressed() = 0;
    virtual void onButtonTimeMinusPressed() = 0;
    virtual void onButtonPwmLowPressed() = 0;
    virtual void onButtonPwmHighPressed() = 0;
    virtual void onButtonTriggerPressed()=0;

    virtual uint32_t getTDivCount() const = 0;      // Returns the of x-axis grid count

protected:
    GuiObserver() {}
};

} // namespace interface
#endif // INTERFACE_GUI_OBSERVER_H
