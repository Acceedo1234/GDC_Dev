/*
 * businesslogic.c
 *
 *  Created on: 02-Oct-2023
 *      Author: acceedo
 */
#include "main.h"
#include "ace_businesslogic.h"

#define decode_automanual 0
#define decode_cycleStart 1
#define decode_Emergency  2
#define decode_ramcloseswitch 3
#define decode_ramopenswitch 4
#define decode_Tilting_Up_Switch 5
#define decode_Tilting_down_switch 6
#define decode_Ejection_In 7
#define decode_Ejection_Output 8
#define decode_Slider_In_Switch 9
#define decode_Slider_Out_Switch 10
#define decode_Motor_Switch 11
#define decode_Station_Conformation 12
#define decode_Robo_Acknowledgment 13
#define decode_Ram_Close_Sensor 14

#define ON 1
#define OFF 0

#define BITREAD(value,nbit) ((value) & (1<<nbit))

typedef struct
{
	GPIO_PinState Auto_Manual;
	GPIO_PinState cycleStart;
	GPIO_PinState Emergency;
	GPIO_PinState Ram_close_switch;
	GPIO_PinState Ram_Open_Switch;
	GPIO_PinState Tilting_Up_Switch;
	GPIO_PinState Tilting_down_switch;
	GPIO_PinState Ejection_In;
	GPIO_PinState Ejection_Output;
	GPIO_PinState Slider_In_Switch;
	GPIO_PinState Slider_Out_Switch;
	GPIO_PinState Motor_Switch;
	GPIO_PinState Station_Conformation;
	GPIO_PinState Robo_Acknowledgment;
	GPIO_PinState Ram_Close_Sensor;
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
uint16_t Inputs_Status;

uint16_t TIltingup;
uint16_t tinltingdown;
uint16_t CuringTime;
uint16_t sliderin;
uint16_t SLiderout;
uint16_t Ejectionon;
uint16_t Ejectionoff;

uint8_t current_state_auto;

void Auto_business_logic(uint16_t input_status);
void Manual_business_logic(uint16_t input_status);

void gdc_businesslogic(void)
{
	/*Read the inputs*/
	input.Auto_Manual 			=	HAL_GPIO_ReadPin(GPIOB,Auto_Manual_Switch_Pin);
	if(input.Auto_Manual == GPIO_PIN_SET){
		Inputs_Status = Inputs_Status & ~(1 << 0);
	}else{
		Inputs_Status = Inputs_Status |(1 <<0);
	}

	input.cycleStart 			=	HAL_GPIO_ReadPin(GPIOE,CycleStart_Switch_Pin);
	if(input.cycleStart == GPIO_PIN_SET){
		Inputs_Status = Inputs_Status & ~(1 << 1);
	}else{
		Inputs_Status = Inputs_Status |(1 <<1);
	}
	input.Emergency 			=	HAL_GPIO_ReadPin(GPIOB,Emergency_Switch_Pin);
	if(input.Emergency == GPIO_PIN_SET){
		Inputs_Status = Inputs_Status & ~(1 << 2);
	}else{
		Inputs_Status = Inputs_Status |(1 <<2);
	}

	input.Ram_close_switch 		=	HAL_GPIO_ReadPin(GPIOE,RampClose_Switch_Pin);
	if(input.Ram_close_switch == GPIO_PIN_SET){
		Inputs_Status = Inputs_Status & ~(1 << 3);
	}else{
		Inputs_Status = Inputs_Status |(1 <<3);
	}
	input.Ram_Open_Switch 		=	HAL_GPIO_ReadPin(GPIOE,RampOpen_Switch_Pin);
	if(input.Ram_Open_Switch == GPIO_PIN_SET){
		Inputs_Status = Inputs_Status & ~(1 << 4);
	}else{
		Inputs_Status = Inputs_Status |(1 <<4);
	}
	input.Tilting_Up_Switch 	=	HAL_GPIO_ReadPin(GPIOE,TiltingUp_Switch_Pin);
	if(input.Tilting_Up_Switch == GPIO_PIN_SET){
		Inputs_Status = Inputs_Status & ~(1 << 5);
	}else{
		Inputs_Status = Inputs_Status |(1 <<5);
	}
	input.Tilting_down_switch 	=	HAL_GPIO_ReadPin(GPIOE,TiltingDown_Switch_Pin);
	if(input.Tilting_down_switch == GPIO_PIN_SET){
		Inputs_Status = Inputs_Status & ~(1 << 6);
	}else{
		Inputs_Status = Inputs_Status |(1 <<6);
	}
	input.Ejection_In 			=	HAL_GPIO_ReadPin(GPIOE,EjectionIn_Switch_Pin);
	if(input.Ejection_In == GPIO_PIN_SET){
		Inputs_Status = Inputs_Status & ~(1 << 7);
	}else{
		Inputs_Status = Inputs_Status |(1 <<7);
	}
	input.Ejection_Output 		=	HAL_GPIO_ReadPin(GPIOE,EjectionOut_Switch_Pin);
	if(input.Ejection_Output == GPIO_PIN_SET){
		Inputs_Status = Inputs_Status & ~(1 << 8);
	}else{
		Inputs_Status = Inputs_Status |(1 <<8);
	}
	input.Slider_In_Switch 		=	HAL_GPIO_ReadPin(GPIOE,SliderIn_Switch_Pin);
	if(input.Slider_In_Switch == GPIO_PIN_SET){
		Inputs_Status = Inputs_Status & ~(1 << 9);
	}else{
		Inputs_Status = Inputs_Status |(1 <<9);
	}
	input.Slider_Out_Switch 	=	HAL_GPIO_ReadPin(GPIOE,SliderOut_Switch_Pin);
	if(input.Slider_Out_Switch == GPIO_PIN_SET){
		Inputs_Status = Inputs_Status & ~(1 << 10);
	}else{
		Inputs_Status = Inputs_Status |(1 <<10);
	}
	input.Motor_Switch 			=	0;//HAL_GPIO_ReadPin(GPIOE,Auto_Manual_Switch_Pin);
	Inputs_Status = Inputs_Status |(input.Motor_Switch <<11);
	input.Station_Conformation 	=	0;//HAL_GPIO_ReadPin(GPIOE,Auto_Manual_Switch_Pin);
	Inputs_Status = Inputs_Status |(input.Station_Conformation <<12);
	input.Robo_Acknowledgment 	=	0;//HAL_GPIO_ReadPin(GPIOE,Auto_Manual_Switch_Pin);
	Inputs_Status = Inputs_Status |(input.Robo_Acknowledgment <<13);
	input.Ram_Close_Sensor 		=	0;//HAL_GPIO_ReadPin(GPIOE,Auto_Manual_Switch_Pin);
	Inputs_Status = Inputs_Status |(input.Ram_Close_Sensor <<14);

	if(input.Auto_Manual == GPIO_PIN_SET){//execute auto code
		Auto_business_logic(Inputs_Status);
	}
	else{//execute manual code
		Manual_business_logic(Inputs_Status);
	}
}


void Auto_business_logic(uint16_t input_status)
{
	switch(current_state_auto)
	{
		case 0://wait for cycle start
			current_state_auto=0;
			if(BITREAD(input_status,decode_cycleStart) == ON){
				current_state_auto=1;
			}
		break;
		case 1://Check preconditions
			if((BITREAD(input_status,decode_ramcloseswitch) == OFF)&&(BITREAD(input_status,decode_ramopenswitch) == ON))
			{
				//if(BITREAD(input_status,decode_ramcloseswitch))
			}
		break;

		default:
		break;
	}
}

void Manual_business_logic(uint16_t input_status)
{

}
