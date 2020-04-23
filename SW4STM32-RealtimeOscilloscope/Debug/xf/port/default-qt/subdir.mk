################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/src/xf/port/default-qt/mutex-default.cpp \
C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/src/xf/port/default-qt/thread-default.cpp 

OBJS += \
./xf/port/default-qt/mutex-default.o \
./xf/port/default-qt/thread-default.o 

CPP_DEPS += \
./xf/port/default-qt/mutex-default.d \
./xf/port/default-qt/thread-default.d 


# Each subdirectory must supply rules for building sources it contributes
xf/port/default-qt/mutex-default.o: C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/src/xf/port/default-qt/mutex-default.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw/ugfx/boards/base/STM32F746-Discovery" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/ui-gen" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/config" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/platform/f7-disco-gcc" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/platform/f7-disco-gcc/mcu" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw/ugfx" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw/ugfx/src/gdisp/mcufont" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/xf/include" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/xf/port" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/xf/port/default-idf" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

xf/port/default-qt/thread-default.o: C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/src/xf/port/default-qt/thread-default.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw/ugfx/boards/base/STM32F746-Discovery" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/ui-gen" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/config" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/platform/f7-disco-gcc" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/platform/f7-disco-gcc/mcu" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw/ugfx" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw/ugfx/src/gdisp/mcufont" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/xf/include" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/xf/port" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/xf/port/default-idf" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


