################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include xf/port/stm32cube-cmsis-freertos/subdir.mk
-include xf/port/idf-stm32cube/subdir.mk
-include xf/port/idf-qt/subdir.mk
-include xf/port/default-qt/subdir.mk
-include xf/port/default-idf/subdir.mk
-include xf/port/default-cmsis-os/subdir.mk
-include xf/port/default/subdir.mk
-include xf/port/active-qt/subdir.mk
-include xf/core/subdir.mk
-include ui-gen/subdir.mk
-include startup/subdir.mk
-include platform/f7-disco-gcc/mcu/hal/subdir.mk
-include platform/f7-disco-gcc/mcu/critical/subdir.mk
-include platform/f7-disco-gcc/board/subdir.mk
-include mdw/ugfx/src/gwin/subdir.mk
-include mdw/ugfx/src/gtrans/subdir.mk
-include mdw/ugfx/src/gtimer/subdir.mk
-include mdw/ugfx/src/gqueue/subdir.mk
-include mdw/ugfx/src/gos/subdir.mk
-include mdw/ugfx/src/gmisc/subdir.mk
-include mdw/ugfx/src/ginput/subdir.mk
-include mdw/ugfx/src/gfile/subdir.mk
-include mdw/ugfx/src/gevent/subdir.mk
-include mdw/ugfx/src/gdriver/subdir.mk
-include mdw/ugfx/src/gdisp/mcufont/subdir.mk
-include mdw/ugfx/src/gdisp/fonts/subdir.mk
-include mdw/ugfx/src/gdisp/subdir.mk
-include mdw/ugfx/src/gaudio/subdir.mk
-include mdw/ugfx/src/gadc/subdir.mk
-include mdw/ugfx/src/subdir.mk
-include mdw/ugfx/drivers/ginput/touch/FT5336/subdir.mk
-include mdw/ugfx/drivers/gdisp/STM32LTDC/subdir.mk
-include mdw/ugfx/boards/base/STM32F746-Discovery/subdir.mk
-include mdw/trace/examples/subdir.mk
-include mdw/sig-gen/subdir.mk
-include app/interface/subdir.mk
-include app/subdir.mk
-include Src/subdir.mk
-include Drivers/STM32F7xx_HAL_Driver/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: SW4STM32-RealtimeOscilloscope.elf

# Tool invocations
SW4STM32-RealtimeOscilloscope.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU G++ Linker'
	arm-none-eabi-g++ -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -specs=nosys.specs -specs=nano.specs -T"../STM32F746NGHx_FLASH.ld" -Wl,-Map=output.map -Wl,--gc-sections -fno-exceptions -fno-rtti -o "SW4STM32-RealtimeOscilloscope.elf" @"objects.list" $(USER_OBJS) $(LIBS) -lm
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	-@echo 'Generating hex and Printing size information:'
	arm-none-eabi-objcopy -O ihex "SW4STM32-RealtimeOscilloscope.elf" "SW4STM32-RealtimeOscilloscope.hex"
	arm-none-eabi-size "SW4STM32-RealtimeOscilloscope.elf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
