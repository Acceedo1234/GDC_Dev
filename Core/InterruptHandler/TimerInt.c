/*
 * TimerInt.c
 *
 *  Created on: Aug 26, 2023
 *      Author: DINESH
 */

#include "main.h"
#include "TimerInt.h"
#include "ace_businesslogic.h"

#define Set_Offset_Slider_Time 			300
#define Set_Offset_RampClose_Timer 		200
#define Set_Offset_Tiltingup_Timer 		200
#define Set_Hold_Pouringwait_Timer 		200
#define Set_Offset_Tilting_Timer 		200
#define Set_Hold_Curing_Timer 			200
#define Set_Offset_Rampopen_Timer 		200
#define Set_Offset_Sliderout_Timer  	200
#define Set_Offset_EjectionIn_Timer 	200
#define Set_Offset_Ejectionout_Timer 	200

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
uint16_t Start_Offset_Slider_Counter;
uint8_t Start_Offset_RampClose_Counter;
uint8_t Start_Offset_Tiltingup_Counter;
uint8_t Start_Hold_Poring_Counter;
uint8_t Start_Offset_Tilting_Counter;
uint8_t Start_Hold_Curing_Counter;
uint8_t Start_Offset_Rampopen_Counter;
uint8_t Start_Offset_Sliderout_Counter;
uint8_t Start_Offset_EjectionIn_Counter;
uint8_t Start_Offset_Ejectionout_Counter;

uint8_t Flag1Sec;
uint8_t Flag200ms;
uint8_t Flag5msTM2;
uint8_t Flag500ms;
uint8_t Complete_Offset_Timer_Slider;
uint8_t Complete_Offset_RampClose_Timer;
uint8_t Complete_Offset_Tiltingup_Timer;
uint8_t Complete_Hold_Pouringwait_Timer;
uint8_t Complete_Offset_Tilting_Timer;
uint8_t Complete_Hold_Curing_Timer;
uint8_t Complete_Offset_Rampopen_Timer;
uint8_t Complete_Offset_Sliderout_Timer;
uint8_t Complete_Offset_EjectionIn_Timer;
uint8_t Complete_Offset_Ejectionout_Timer;

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

			if(Start_Offset_Slider_Timer)
			{//Set_Offset_Slider_Time
				if(++Start_Offset_Slider_Counter >= sliderin)
				{
					Start_Offset_Slider_Counter=0;
					Start_Offset_Slider_Timer=0;
					Complete_Offset_Timer_Slider=1;
				}
			}
			if(Start_Offset_RampClose_Timer)
			{
				if(++Start_Offset_RampClose_Counter >= Set_Offset_RampClose_Timer)
				{
					Start_Offset_RampClose_Timer=0;
					Start_Offset_RampClose_Counter=0;
					Complete_Offset_RampClose_Timer=1;
				}
			}
			if(Start_Offset_Tiltingup_Timer)
			{//Set_Offset_Tiltingup_Timer
				if(++Start_Offset_Tiltingup_Counter >= TIltingup)
				{
					Start_Offset_Tiltingup_Timer=0;
					Start_Offset_Tiltingup_Counter=0;
					Complete_Offset_Tiltingup_Timer=1;
				}
			}
			if(Start_Hold_Pouringwait_Timer)
			{
				if(++Start_Hold_Poring_Counter >= Set_Hold_Pouringwait_Timer)
				{
					Start_Hold_Pouringwait_Timer=0;
					Start_Hold_Poring_Counter=0;
					Complete_Hold_Pouringwait_Timer=1;
				}
			}
			if(Start_Offset_Tilting_Timer)
			{//Set_Offset_Tilting_Timer
				if(++Start_Offset_Tilting_Counter >= tinltingdown)
				{
					Start_Offset_Tilting_Timer=0;
					Start_Offset_Tilting_Counter=0;
					Complete_Offset_Tilting_Timer=1;
				}
			}
			if(Start_Hold_Curing_Timer)
			{//Set_Hold_Curing_Timer
				if(++Start_Hold_Curing_Counter >= CuringTime)
				{
					Start_Hold_Curing_Timer=0;
					Start_Hold_Curing_Counter=0;
					Complete_Hold_Curing_Timer=1;
				}
			}
			if(Start_Offset_Rampopen_Timer)
			{
				if(++Start_Offset_Rampopen_Counter >= Set_Hold_Curing_Timer)
				{
					Start_Offset_Rampopen_Timer=0;
					Start_Offset_Rampopen_Counter=0;
					Complete_Offset_Rampopen_Timer=1;
				}
			}
			if(Start_Offset_Sliderout_Timer)
			{//Set_Offset_Sliderout_Timer
				if(++Start_Offset_Sliderout_Counter >=SLiderout)
				{
					Start_Offset_Sliderout_Timer=0;
					Start_Offset_Sliderout_Counter=0;
					Complete_Offset_Sliderout_Timer=1;
				}
			}
			if(Start_Offset_EjectionIn_Timer)
			{//Set_Offset_EjectionIn_Timer
				if(++Start_Offset_EjectionIn_Counter >= Ejectionon)
				{
					Start_Offset_EjectionIn_Timer=0;
					Start_Offset_EjectionIn_Counter=0;
					Complete_Offset_EjectionIn_Timer=1;
				}
			}
			if(Start_Offset_Ejectionout_Timer)// Set_Offset_Ejectionout_Timer
			{
				if(++Start_Offset_Ejectionout_Counter >= Ejectionoff)
				{
					Start_Offset_Ejectionout_Timer=0;
					Start_Offset_Ejectionout_Counter=0;
					Complete_Offset_Ejectionout_Timer=1;
				}
			}
		}
		if(++Count500ms >= 4)
		{
			Count500ms=0;
			Flag500ms = 1;
		}
	}
}

void InputOutputTest(void)
{
/*	HAL_GPIO_WritePin(GPIOD, MotorOn_Pin|MotorOff_Pin|RampOpen_Pin|RampCLose_Pin
	                          |TiltingUp_Pin|TiltingDown_Pin|SkiderOut_Pin|SliderIn_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(GPIOC, EjectionOn_Pin|EjectionOff_Pin|RoboRelay_Pin, GPIO_PIN_SET);*/

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

