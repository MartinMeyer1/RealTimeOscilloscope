#ifndef SIGGEN_PWMGENERATOR_CONFIG_H
#define SIGGEN_PWMGENERATOR_CONFIG_H

#include "mcu/mcu.h"

#define ENABLE_SIGGEN_PWMGENERATOR              0               /* Enables/disables usage of PwmGenerator */

extern "C" TIM_HandleTypeDef htim10;                            // Defined in main.c

#define SIGGEN_PWM_TIMER_HANDLE                 htim10          /* Hardware timer used for PWM generation */

#endif // SIGGEN_PWMGENERATOR_CONFIG_H
