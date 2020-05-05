################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1/port.c 

OBJS += \
./Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1/port.o 

C_DEPS += \
./Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1/port.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1/%.o: ../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw/ugfx/boards/base/STM32F746-Discovery" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw/ugfx/src/gdisp/mcufont" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/xf/port/default-cmsis-os" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../SW4STM32-RealtimeOscilloscope/middlewares/third_party/freertos/source/cmsis_rtos" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../SW4STM32-RealtimeOscilloscope/middlewares/third_party/freertos/source/include" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../SW4STM32-RealtimeOscilloscope/middlewares/third_party/freertos/source/portable/gcc/arm_cm7/r0p1" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/ui-gen" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/config" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/platform/f7-disco-gcc" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw/ugfx" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/platform/f7-disco-gcc/mcu" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/xf/include" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/xf/port" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/xf/port/default-idf" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/CMSIS/Include" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Middlewares/Third_Party/FreeRTOS/Source/include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


