#include <assert.h>
#include "main.h"
#include "pwmgenerator.h"

#if defined(ENABLE_SIGGEN_PWMGENERATOR) && (ENABLE_SIGGEN_PWMGENERATOR != 0)

namespace siggen {

PwmGenerator * PwmGenerator::_pInstance(nullptr);

PwmGenerator::PwmGenerator(TIM_HandleTypeDef * htim, uint32_t channel /* = TIM_CHANNEL_1 */) :
 htim(htim),
 TIMER_CHANNEL(channel),
 dutyCyle(50)
{
    assert(!_pInstance);    // Only one instance of this class allowed!
    _pInstance = this;

    assert(htim);           // Null pointer not allowed!
}

//static
PwmGenerator & PwmGenerator::getInstance()
{
    assert(_pInstance);     // Create first an instance!
    return *_pInstance;
}

void PwmGenerator::start()
{
    HAL_TIM_PWM_Start(htim, TIMER_CHANNEL);
}

void PwmGenerator::stop()
{
    HAL_TIM_PWM_Stop(htim, TIMER_CHANNEL);
}

void PwmGenerator::setFrequency(uint32_t frequency)
{
    const uint32_t periodInUs = 1000000 / frequency;

    stop();

    htim->Init.Period = periodInUs;                 // Set frequency (period)
    if (HAL_TIM_PWM_Init(htim) != HAL_OK)
    {
        Error_Handler();
    }

    updateDutyCycle(/*restartTimer = */ false);

    start();
}

void PwmGenerator::setDutyCycle(uint8_t dutyCycle)
{
    if (dutyCycle <= 100)
    {
        if (this->dutyCyle != dutyCycle)
        {
            this->dutyCyle = dutyCycle;

            updateDutyCycle();
        }
    }
}

void PwmGenerator::updateDutyCycle(bool restartTimer /* = true */)
{
    TIM_OC_InitTypeDef sConfigOC = {0};

    if (restartTimer)
        stop();

    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = htim->Init.Period * dutyCyle / 100;  // Set duty cycle
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    if (HAL_TIM_PWM_ConfigChannel(htim, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
    {
        Error_Handler();
    }

    if (restartTimer)
        start();
}

} // namespace siggen
#endif // ENABLE_SIGGEN_PWMGENERATOR
