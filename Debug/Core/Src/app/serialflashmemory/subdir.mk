################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/app/serialflashmemory/flashmemory.c 

OBJS += \
./Core/Src/app/serialflashmemory/flashmemory.o 

C_DEPS += \
./Core/Src/app/serialflashmemory/flashmemory.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/app/serialflashmemory/%.o Core/Src/app/serialflashmemory/%.su: ../Core/Src/app/serialflashmemory/%.c Core/Src/app/serialflashmemory/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F107xC -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"E:/SourceTree/GDC_dev/Core/InterruptHandler" -I"E:/SourceTree/GDC_dev/Core/wq5264" -I"E:/SourceTree/GDC_dev/Core/Src/app/modbus" -I"E:/SourceTree/GDC_dev/Core/Src/app/logic" -I"E:/SourceTree/GDC_dev/Core/Src/app/common" -I"E:/SourceTree/GDC_dev/Core/Src/app/serialflashmemory" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-app-2f-serialflashmemory

clean-Core-2f-Src-2f-app-2f-serialflashmemory:
	-$(RM) ./Core/Src/app/serialflashmemory/flashmemory.d ./Core/Src/app/serialflashmemory/flashmemory.o ./Core/Src/app/serialflashmemory/flashmemory.su

.PHONY: clean-Core-2f-Src-2f-app-2f-serialflashmemory

