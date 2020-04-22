/*
 * isrs.cpp
 *
 *  Created on: 22 avr. 2020
 *      Author: meyer
 */
#include "stm32f7xx_hal.h"

extern "C" void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef * hadc)
{
	volatile uint32_t value = HAL_ADC_GetValue(hadc);
}

extern "C" void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim)
{

}
