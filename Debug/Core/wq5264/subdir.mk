################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/wq5264/w25qxx.c 

OBJS += \
./Core/wq5264/w25qxx.o 

C_DEPS += \
./Core/wq5264/w25qxx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/wq5264/%.o Core/wq5264/%.su: ../Core/wq5264/%.c Core/wq5264/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F107xC -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"E:/SourceTree/GDC_dev/Core/InterruptHandler" -I"E:/SourceTree/GDC_dev/Core/wq5264" -I"E:/SourceTree/GDC_dev/Core/Src/app/modbus" -I"E:/SourceTree/GDC_dev/Core/Src/app/logic" -I"E:/SourceTree/GDC_dev/Core/Src/app/common" -I"E:/SourceTree/GDC_dev/Core/Src/app/serialflashmemory" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-wq5264

clean-Core-2f-wq5264:
	-$(RM) ./Core/wq5264/w25qxx.d ./Core/wq5264/w25qxx.o ./Core/wq5264/w25qxx.su

.PHONY: clean-Core-2f-wq5264

