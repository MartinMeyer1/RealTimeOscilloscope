/*
 * isrs.cpp
 *
 *  Created on: 22 avr. 2020
 *      Author: meyer
 */
#include "stm32f7xx_hal.h"
#include "main.h"

uint16_t adcValuesBuffer[ADC_VALUES_BUFFER_SIZE];

extern "C" void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef * hadc)
{
	static int i=0;
	volatile uint32_t value = HAL_ADC_GetValue(hadc);
	adcValuesBuffer[i]=value;
	i++;
	i=i%ADC_VALUES_BUFFER_SIZE;
}

extern "C" void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim)
{

}
