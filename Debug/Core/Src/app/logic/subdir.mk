################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/app/logic/ace_businesslogic.c 

OBJS += \
./Core/Src/app/logic/ace_businesslogic.o 

C_DEPS += \
./Core/Src/app/logic/ace_businesslogic.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/app/logic/%.o Core/Src/app/logic/%.su: ../Core/Src/app/logic/%.c Core/Src/app/logic/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F107xC -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/SourceTree/GDC_dev/Core/InterruptHandler" -I"D:/SourceTree/GDC_dev/Core/wq5264" -I"D:/SourceTree/GDC_dev/Core/Src/app/modbus" -I"D:/SourceTree/GDC_dev/Core/Src/app/logic" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-app-2f-logic

clean-Core-2f-Src-2f-app-2f-logic:
	-$(RM) ./Core/Src/app/logic/ace_businesslogic.d ./Core/Src/app/logic/ace_businesslogic.o ./Core/Src/app/logic/ace_businesslogic.su

.PHONY: clean-Core-2f-Src-2f-app-2f-logic

