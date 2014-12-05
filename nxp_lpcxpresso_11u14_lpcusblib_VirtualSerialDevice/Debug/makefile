################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include example/src/Lib/subdir.mk
-include example/src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: nxp_lpcxpresso_11u14_lpcusblib_VirtualSerialDevice.axf

# Tool invocations
nxp_lpcxpresso_11u14_lpcusblib_VirtualSerialDevice.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"/home/parth/LPCXpresso/workspace/nxp_lpcxpresso_11u14_board_lib/Debug" -L"/home/parth/LPCXpresso/workspace/lpc_chip_11uxx_lib/Debug" -L"/home/parth/LPCXpresso/workspace/nxp_lpcxpresso_11u14_usblib_device/Debug" -Xlinker -Map="nxp_lpcxpresso_11u14_lpcusblib_VirtualSerialDevice.map" -Xlinker --gc-sections -flto -Os -mcpu=cortex-m0 -mthumb -T "nxp_lpcxpresso_11u14_lpcusblib_VirtualSerialDevice_Debug.ld" -o "nxp_lpcxpresso_11u14_lpcusblib_VirtualSerialDevice.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) nxp_lpcxpresso_11u14_lpcusblib_VirtualSerialDevice.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "nxp_lpcxpresso_11u14_lpcusblib_VirtualSerialDevice.axf" ; arm-none-eabi-objcopy -O binary "nxp_lpcxpresso_11u14_lpcusblib_VirtualSerialDevice.axf" "nxp_lpcxpresso_11u14_lpcusblib_VirtualSerialDevice.bin" ; checksum -p LPC11U24_401 -d "nxp_lpcxpresso_11u14_lpcusblib_VirtualSerialDevice.bin"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
