################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/src/xf/port/default/dispatcher-active.cpp \
C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/src/xf/port/default/dispatcher-default.cpp \
C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/src/xf/port/default/resourcefactory-default.cpp \
C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/src/xf/port/default/timeoutmanager-default.cpp \
C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/src/xf/port/default/xf-default.cpp 

OBJS += \
./xf/port/default/dispatcher-active.o \
./xf/port/default/dispatcher-default.o \
./xf/port/default/resourcefactory-default.o \
./xf/port/default/timeoutmanager-default.o \
./xf/port/default/xf-default.o 

CPP_DEPS += \
./xf/port/default/dispatcher-active.d \
./xf/port/default/dispatcher-default.d \
./xf/port/default/resourcefactory-default.d \
./xf/port/default/timeoutmanager-default.d \
./xf/port/default/xf-default.d 


# Each subdirectory must supply rules for building sources it contributes
xf/port/default/dispatcher-active.o: C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/src/xf/port/default/dispatcher-active.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw/ugfx/boards/base/STM32F746-Discovery" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/ui-gen" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/config" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/platform/f7-disco-gcc" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/platform/f7-disco-gcc/mcu" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw/ugfx" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw/ugfx/src/gdisp/mcufont" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/xf/include" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/xf/port" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/xf/port/default-idf" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

xf/port/default/dispatcher-default.o: C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/src/xf/port/default/dispatcher-default.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw/ugfx/boards/base/STM32F746-Discovery" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/ui-gen" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/config" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/platform/f7-disco-gcc" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/platform/f7-disco-gcc/mcu" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw/ugfx" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw/ugfx/src/gdisp/mcufont" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/xf/include" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/xf/port" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/xf/port/default-idf" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

xf/port/default/resourcefactory-default.o: C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/src/xf/port/default/resourcefactory-default.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw/ugfx/boards/base/STM32F746-Discovery" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/ui-gen" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/config" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/platform/f7-disco-gcc" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/platform/f7-disco-gcc/mcu" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw/ugfx" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw/ugfx/src/gdisp/mcufont" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/xf/include" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/xf/port" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/xf/port/default-idf" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

xf/port/default/timeoutmanager-default.o: C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/src/xf/port/default/timeoutmanager-default.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw/ugfx/boards/base/STM32F746-Discovery" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/ui-gen" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/config" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/platform/f7-disco-gcc" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/platform/f7-disco-gcc/mcu" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw/ugfx" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw/ugfx/src/gdisp/mcufont" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/xf/include" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/xf/port" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/xf/port/default-idf" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

xf/port/default/xf-default.o: C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/src/xf/port/default/xf-default.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw/ugfx/boards/base/STM32F746-Discovery" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/ui-gen" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/config" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/platform/f7-disco-gcc" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/platform/f7-disco-gcc/mcu" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw/ugfx" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/mdw/ugfx/src/gdisp/mcufont" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/xf/include" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/xf/port" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/../src/xf/port/default-idf" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/meyer/Saved/Hes/PTR/RealtimeOscilloscope/SW4STM32-RealtimeOscilloscope/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


