/*
 * TimerInt.c
 *
 *  Created on: Aug 26, 2023
 *      Author: DINESH
 */

#include "main.h"
#include "TimerInt.h"

extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;

void InputOutputTest(void);
void InputOutputTest1(void);
void TimerApplicationInit(void);


static uint8_t Count5ms=0;
uint8_t Count1Sec = 0;
uint8_t CycleStart_Switch;
uint8_t Count20ms;
uint8_t Count500ms;

uint8_t Flag1Sec;
uint8_t Flag200ms;
uint8_t Flag5msTM2;
uint8_t Flag500ms;

extern uint16_t Production;

void TimerApplicationInit(void)
{
	HAL_TIM_Base_Start_IT(&htim2);
	HAL_TIM_Base_Start_IT(&htim3);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim == &htim2)
	{
		if(++Count5ms >= 5)
		{
			Flag5msTM2 = 1;
			Count5ms=0;
		}
		if(++Count20ms >= 20){
			Flag200ms=1;
			Count20ms=0;
		}
	}

	if(htim == &htim3)
	{
		if(++Count1Sec >= 10)
		{
			//HAL_GPIO_TogglePin(GPIOD,Relay_1_Pin);
			Count1Sec=0;
			Flag1Sec = 1;
			if(++Production > 1000){Production=0;}
		}
		if(++Count500ms >= 4)
		{
			Count500ms=0;
			Flag500ms = 1;
		}
		InputOutputTest1();
	}
}

void InputOutputTest(void)
{
	HAL_GPIO_WritePin(GPIOD, MotorOn_Pin|MotorOff_Pin|RampOpen_Pin|RampCLose_Pin
	                          |TiltingUp_Pin|TiltingDown_Pin|SkiderOut_Pin|SliderIn_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(GPIOC, EjectionOn_Pin|EjectionOff_Pin|RoboRelay_Pin, GPIO_PIN_SET);

}

void InputOutputTest1(void)
{
	if(HAL_GPIO_ReadPin (GPIOA, CycleStart_Switch_Pin))
	{
		CycleStart_Switch = 1;
	}
	else
	{
		CycleStart_Switch = 0;
	}
}

