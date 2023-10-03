/*
 * businesslogic.c
 *
 *  Created on: 02-Oct-2023
 *      Author: acceedo
 */
#include "main.h"
#include "ace_businesslogic.h"

typedef struct
{
	GPIO_PinState Auto_Manual;
	uint8_t cycleStart;
	uint8_t Emergency;
	uint8_t Ram_close_switch;
	uint8_t Ram_Open_Switch;
	uint8_t Tilting_Up_Switch;
	uint8_t Tilting_down_switch;
	uint8_t Ejection_In;
	uint8_t Ejection_Output;
	uint8_t Slider_In_Switch;
	uint8_t Slider_Out_Switch;
	uint8_t Motor_Switch;
	uint8_t Station_Conformation;
	uint8_t Robo_Acknowledgment;
	uint8_t Ram_Close_Sensor;
}Hw_Inputs;

typedef struct
{
	uint8_t Ram_Open_Valve;
	uint8_t Tilting_Up_Valve;
	uint8_t Tilting_Down_Valve;
}Hw_Outputs;

Hw_Inputs input;
Hw_Outputs output;
uint16_t Inputs_Status;
void gdc_businesslogic(void)
{
	/*Read the inputs*/
	input.Auto_Manual 			=	HAL_GPIO_ReadPin(GPIOB,Auto_Manual_Switch_Pin);
	Inputs_Status = Inputs_Status |(input.Auto_Manual <<0);
	input.cycleStart 			=	HAL_GPIO_ReadPin(GPIOB,CycleStart_Switch_Pin);
	Inputs_Status = Inputs_Status |(input.cycleStart <<1);
	input.Emergency 			=	HAL_GPIO_ReadPin(GPIOB,Emergency_Switch_Pin);
	Inputs_Status = Inputs_Status |(input.Emergency <<2);
	input.Ram_close_switch 		=	HAL_GPIO_ReadPin(GPIOB,RampClose_Switch_Pin);
	Inputs_Status = Inputs_Status |(input.Ram_close_switch <<3);
	input.Ram_Open_Switch 		=	HAL_GPIO_ReadPin(GPIOB,RampOpen_Switch_Pin);
	Inputs_Status = Inputs_Status |(input.Ram_Open_Switch <<4);
	input.Tilting_Up_Switch 	=	HAL_GPIO_ReadPin(GPIOB,TiltingUp_Switch_Pin);
	Inputs_Status = Inputs_Status |(input.Tilting_Up_Switch <<5);
	input.Tilting_down_switch 	=	HAL_GPIO_ReadPin(GPIOB,TiltingDown_Switch_Pin);
	Inputs_Status = Inputs_Status |(input.Tilting_down_switch <<6);
	input.Ejection_In 			=	HAL_GPIO_ReadPin(GPIOB,EjectionIn_Switch_Pin);
	Inputs_Status = Inputs_Status |(input.Ejection_In <<7);
	input.Ejection_Output 		=	HAL_GPIO_ReadPin(GPIOB,EjectionOut_Switch_Pin);
	Inputs_Status = Inputs_Status |(input.Ejection_Output <<8);
	input.Slider_In_Switch 		=	HAL_GPIO_ReadPin(GPIOB,SliderIn_Switch_Pin);
	Inputs_Status = Inputs_Status |(input.Slider_In_Switch <<9);
	input.Slider_Out_Switch 	=	HAL_GPIO_ReadPin(GPIOB,SliderOut_Pin);
	Inputs_Status = Inputs_Status |(input.Slider_Out_Switch <<10);
	input.Motor_Switch 			=	0;//HAL_GPIO_ReadPin(GPIOB,Auto_Manual_Switch_Pin);
	Inputs_Status = Inputs_Status |(input.Motor_Switch <<11);
	input.Station_Conformation 	=	0;//HAL_GPIO_ReadPin(GPIOB,Auto_Manual_Switch_Pin);
	Inputs_Status = Inputs_Status |(input.Station_Conformation <<12);
	input.Robo_Acknowledgment 	=	0;//HAL_GPIO_ReadPin(GPIOB,Auto_Manual_Switch_Pin);
	Inputs_Status = Inputs_Status |(input.Robo_Acknowledgment <<13);
	input.Ram_Close_Sensor 		=	0;//HAL_GPIO_ReadPin(GPIOB,Auto_Manual_Switch_Pin);
	Inputs_Status = Inputs_Status |(input.Ram_Close_Sensor <<14);


/*
	switch()
	{
		case 0:

		break;
	}*/
}
