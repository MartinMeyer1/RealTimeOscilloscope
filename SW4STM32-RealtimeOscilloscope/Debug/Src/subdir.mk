################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/freertos.c \
../Src/main.c \
../Src/stm32f7xx_hal_msp.c \
../Src/stm32f7xx_hal_timebase_tim.c \
../Src/stm32f7xx_it.c \
../Src/system_stm32f7xx.c 

CPP_SRCS += \
../Src/isrs.cpp 

OBJS += \
./Src/freertos.o \
./Src/isrs.o \
./Src/main.o \
./Src/stm32f7xx_hal_msp.o \
./Src/stm32f7xx_hal_timebase_tim.o \
./Src/stm32f7xx_it.o \
./Src/system_stm32f7xx.o 

C_DEPS += \
./Src/freertos.d \
./Src/main.d \
./Src/stm32f7xx_hal_msp.d \
./Src/stm32f7xx_hal_timebase_tim.d \
./Src/stm32f7xx_it.d \
./Src/system_stm32f7xx.d 

CPP_DEPS += \
./Src/isrs.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw/ugfx/boards/base/STM32F746-Discovery" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw/ugfx/src/gdisp/mcufont" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/xf/port/default-cmsis-os" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../SW4STM32-RealtimeOscilloscope/middlewares/third_party/freertos/source/cmsis_rtos" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../SW4STM32-RealtimeOscilloscope/middlewares/third_party/freertos/source/include" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../SW4STM32-RealtimeOscilloscope/middlewares/third_party/freertos/source/portable/gcc/arm_cm7/r0p1" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/ui-gen" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/config" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/platform/f7-disco-gcc" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw/ugfx" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/platform/f7-disco-gcc/mcu" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/xf/include" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/xf/port" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/xf/port/default-idf" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/CMSIS/Include" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Middlewares/Third_Party/FreeRTOS/Source/include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Src/%.o: ../Src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw/ugfx/boards/base/STM32F746-Discovery" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/xf/port/default-cmsis-os" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/ui-gen" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/config" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../SW4STM32-RealtimeOscilloscope/middlewares/third_party/freertos/source/cmsis_rtos" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../SW4STM32-RealtimeOscilloscope/middlewares/third_party/freertos/source/include" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../SW4STM32-RealtimeOscilloscope/middlewares/third_party/freertos/source/portable/gcc/arm_cm7/r0p1" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/platform/f7-disco-gcc" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/platform/f7-disco-gcc/mcu" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw/ugfx" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw/ugfx/src/gdisp/mcufont" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/xf/include" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/xf/port" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/xf/port/default-idf" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/CMSIS/Include" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Middlewares/Third_Party/FreeRTOS/Source/include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


