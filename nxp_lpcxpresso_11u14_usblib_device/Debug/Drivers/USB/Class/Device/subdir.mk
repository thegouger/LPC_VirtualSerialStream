################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/USB/Class/Device/AudioClassDevice.c \
../Drivers/USB/Class/Device/CDCClassDevice.c \
../Drivers/USB/Class/Device/HIDClassDevice.c \
../Drivers/USB/Class/Device/MIDIClassDevice.c \
../Drivers/USB/Class/Device/MassStorageClassDevice.c \
../Drivers/USB/Class/Device/RNDISClassDevice.c 

OBJS += \
./Drivers/USB/Class/Device/AudioClassDevice.o \
./Drivers/USB/Class/Device/CDCClassDevice.o \
./Drivers/USB/Class/Device/HIDClassDevice.o \
./Drivers/USB/Class/Device/MIDIClassDevice.o \
./Drivers/USB/Class/Device/MassStorageClassDevice.o \
./Drivers/USB/Class/Device/RNDISClassDevice.o 

C_DEPS += \
./Drivers/USB/Class/Device/AudioClassDevice.d \
./Drivers/USB/Class/Device/CDCClassDevice.d \
./Drivers/USB/Class/Device/HIDClassDevice.d \
./Drivers/USB/Class/Device/MIDIClassDevice.d \
./Drivers/USB/Class/Device/MassStorageClassDevice.d \
./Drivers/USB/Class/Device/RNDISClassDevice.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/USB/Class/Device/%.o: ../Drivers/USB/Class/Device/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DDEBUG -D__CODE_RED -DCORE_M0 -D__LPC11U1X__ -DUSB_DEVICE_ONLY -D__NEWLIB__ -I"/home/parth/LPCXpresso/workspace/lpc_chip_11uxx_lib/inc" -I"/home/parth/LPCXpresso/workspace/nxp_lpcxpresso_11u14_board_lib/inc" -O3 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -D__NEWLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


