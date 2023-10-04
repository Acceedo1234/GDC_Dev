################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/app/common/uart_handler.c 

OBJS += \
./Core/Src/app/common/uart_handler.o 

C_DEPS += \
./Core/Src/app/common/uart_handler.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/app/common/%.o Core/Src/app/common/%.su: ../Core/Src/app/common/%.c Core/Src/app/common/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F107xC -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/SourceTree/gdc_dev/Core/InterruptHandler" -I"D:/SourceTree/gdc_dev/Core/wq5264" -I"D:/SourceTree/gdc_dev/Core/Src/app/modbus" -I"D:/SourceTree/gdc_dev/Core/Src/app/logic" -I"D:/SourceTree/gdc_dev/Core/Src/app/common" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-app-2f-common

clean-Core-2f-Src-2f-app-2f-common:
	-$(RM) ./Core/Src/app/common/uart_handler.d ./Core/Src/app/common/uart_handler.o ./Core/Src/app/common/uart_handler.su

.PHONY: clean-Core-2f-Src-2f-app-2f-common

