#ifndef SIGGEN_PWM_GENERATOR_H
#define SIGGEN_PWM_GENERATOR_H

#include "config/siggen-pwmgenerator-config.h"

#if defined(ENABLE_SIGGEN_PWMGENERATOR) && (ENABLE_SIGGEN_PWMGENERATOR != 0)
#include "mcu/mcu.h"

namespace siggen {

/**
 * @brief PWM signal generator to produce reference signal.
 */
class PwmGenerator
{
public:
    PwmGenerator(TIM_HandleTypeDef * htim, uint32_t channel = TIM_CHANNEL_1);
    PwmGenerator(const PwmGenerator &) = delete;
    const PwmGenerator & operator =(const PwmGenerator &) = delete;

    static PwmGenerator & getInstance();            ///< Returns a reference to the single instance.

    void start();                                   ///< Starts PWM generator.
    void stop();                                    ///< Stop PWM generation.
    void setFrequency(uint32_t frequency);          ///< Sets PWM frequency in Hz.
    void setDutyCycle(uint8_t dutyCycle);           ///< Sets duty cycle of the PWM (0 - 100. Default: 50)

protected:
    void updateDutyCycle(bool restartTimer = true);

protected:
    static PwmGenerator * _pInstance;               ///< Pointer to single instance.
    TIM_HandleTypeDef * htim;                       ///< Hardware timer to generate the PWM signal.
    const uint32_t TIMER_CHANNEL;                   ///< TIM channel to be used.
    uint8_t dutyCyle;                               ///< Holds actual duty cycle.
};

} // namespace siggen
#endif // ENABLE_SIGGEN_PWMGENERATOR
#endif // SIGGEN_PWM_GENERATOR_H
