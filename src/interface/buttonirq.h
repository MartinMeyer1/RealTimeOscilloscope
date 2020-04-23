#ifndef INTERFACE_BUTTONIRQ_H
#define INTERFACE_BUTTONIRQ_H

namespace interface {

/**
 * @brief Interface needed by the Interrupt Service Routine (ISR).
 *
 * This interface is needed by the ISR which reacts on button
 * changes (level changes on GPIOs).
 *
 * Every time a level change on the buttons GPIOs is detected,
 * the ISR calls this method.
 */
class ButtonIrq
{
protected:
    virtual ~ButtonIrq() {}

	virtual void onIrq() = 0;	///< @brief Called by the ISR.

protected:
	ButtonIrq() {}              ///< Not allowing to instantiate object of interface.
};

} // namespace interface
#endif // INTERFACE_BUTTONIRQ_H
