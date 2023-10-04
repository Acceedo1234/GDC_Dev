################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/InterruptHandler/SerialInt.c \
../Core/InterruptHandler/TimerInt.c 

OBJS += \
./Core/InterruptHandler/SerialInt.o \
./Core/InterruptHandler/TimerInt.o 

C_DEPS += \
./Core/InterruptHandler/SerialInt.d \
./Core/InterruptHandler/TimerInt.d 


# Each subdirectory must supply rules for building sources it contributes
Core/InterruptHandler/%.o Core/InterruptHandler/%.su: ../Core/InterruptHandler/%.c Core/InterruptHandler/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F107xC -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/SourceTree/gdc_dev/Core/InterruptHandler" -I"D:/SourceTree/gdc_dev/Core/wq5264" -I"D:/SourceTree/gdc_dev/Core/Src/app/modbus" -I"D:/SourceTree/gdc_dev/Core/Src/app/logic" -I"D:/SourceTree/gdc_dev/Core/Src/app/common" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-InterruptHandler

clean-Core-2f-InterruptHandler:
	-$(RM) ./Core/InterruptHandler/SerialInt.d ./Core/InterruptHandler/SerialInt.o ./Core/InterruptHandler/SerialInt.su ./Core/InterruptHandler/TimerInt.d ./Core/InterruptHandler/TimerInt.o ./Core/InterruptHandler/TimerInt.su

.PHONY: clean-Core-2f-InterruptHandler

