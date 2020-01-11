################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/BLDCMotorControl.c \
../source/Delays.c \
../source/PWM_functions.c \
../source/RGB_LEDS.c \
../source/semihost_hardfault.c 

OBJS += \
./source/BLDCMotorControl.o \
./source/Delays.o \
./source/PWM_functions.o \
./source/RGB_LEDS.o \
./source/semihost_hardfault.o 

C_DEPS += \
./source/BLDCMotorControl.d \
./source/Delays.d \
./source/PWM_functions.d \
./source/RGB_LEDS.d \
./source/semihost_hardfault.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"/home/leandro/MEGA/Dron/FreedomProjects/BLDCMotorControl/board" -I"/home/leandro/MEGA/Dron/FreedomProjects/BLDCMotorControl/source" -I"/home/leandro/MEGA/Dron/FreedomProjects/BLDCMotorControl" -I"/home/leandro/MEGA/Dron/FreedomProjects/BLDCMotorControl/drivers" -I"/home/leandro/MEGA/Dron/FreedomProjects/BLDCMotorControl/device" -I"/home/leandro/MEGA/Dron/FreedomProjects/BLDCMotorControl/CMSIS" -I"/home/leandro/MEGA/Dron/FreedomProjects/BLDCMotorControl/component/uart" -I"/home/leandro/MEGA/Dron/FreedomProjects/BLDCMotorControl/utilities" -I"/home/leandro/MEGA/Dron/FreedomProjects/BLDCMotorControl/component/serial_manager" -I"/home/leandro/MEGA/Dron/FreedomProjects/BLDCMotorControl/component/lists" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


