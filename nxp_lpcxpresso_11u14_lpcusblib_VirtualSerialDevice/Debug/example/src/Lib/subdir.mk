################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../example/src/Lib/UsbRom.c 

OBJS += \
./example/src/Lib/UsbRom.o 

C_DEPS += \
./example/src/Lib/UsbRom.d 


# Each subdirectory must supply rules for building sources it contributes
example/src/Lib/%.o: ../example/src/Lib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DDEBUG -D__USE_LPCOPEN -DCORE_M0 -D__LPC11U1X__ -DUSB_DEVICE_ONLY -D__NEWLIB__ -I"/home/parth/LPCXpresso/workspace/nxp_lpcxpresso_11u14_lpcusblib_VirtualSerialDevice/example/src" -I"/home/parth/LPCXpresso/workspace/nxp_lpcxpresso_11u14_lpcusblib_VirtualSerialDevice/example/src/Lib" -I"/home/parth/LPCXpresso/workspace/lpc_chip_11uxx_lib/inc" -I"/home/parth/LPCXpresso/workspace/nxp_lpcxpresso_11u14_board_lib/inc" -I"/home/parth/LPCXpresso/workspace/nxp_lpcxpresso_11u14_usblib_device/Drivers/USB" -Os -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -D__NEWLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


