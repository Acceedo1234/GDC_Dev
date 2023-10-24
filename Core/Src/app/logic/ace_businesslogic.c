/*
 * businesslogic.c
 *
 *  Created on: 02-Oct-2023
 *      Author: acceedo
 */
#include "main.h"
#include "ace_businesslogic.h"
#include "TimerInt.h"

#define SLIDERVALVE 1
#define ROBOAUTOMATIC 0

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
	GPIO_PinState MotorOn_Switch;
	GPIO_PinState MotorOff_Switch;
	GPIO_PinState Station_Conformation;
	GPIO_PinState Robo_Acknowledgment;
	GPIO_PinState Ram_Open_Sensor;
	GPIO_PinState Ram_Close_Sensor;
	GPIO_PinState TiltingUp_Sensor;
	GPIO_PinState TiltingDown_Sensor;
}Hw_Inputs;

typedef struct
{
	GPIO_PinState Ram_Close_Valve;
	GPIO_PinState Ram_Open_Valve;
	GPIO_PinState Tilting_Up_Valve;
	GPIO_PinState Tilting_Down_Valve;
	GPIO_PinState Slider_In_Valve;
	GPIO_PinState Slider_Out_Valve;
	GPIO_PinState Ejection_In_Valve;
	GPIO_PinState Ejection_Out_Valve;
	GPIO_PinState Motor_On_Off_valve;
	GPIO_PinState Robo_Status_Valve;
}Hw_Outputs;

Hw_Inputs input;
Hw_Outputs output;
uint16_t Inputs_Status;
uint16_t Inputs_Status_2;

uint16_t TIltingup;
uint16_t tinltingdown;
uint16_t CuringTime;
uint16_t sliderin;
uint16_t SLiderout;
uint16_t Ejectionon;
uint16_t Ejectionoff;

uint8_t current_state_auto;
uint8_t Start_Offset_Slider_Timer;
uint8_t Start_Offset_RampClose_Timer;
uint8_t Start_Offset_Tiltingup_Timer;
uint8_t Start_Hold_Pouringwait_Timer;
uint8_t Start_Offset_Tilting_Timer;
uint8_t Start_Hold_Curing_Timer;
uint8_t Start_Offset_Rampopen_Timer;
uint8_t Start_Offset_Sliderout_Timer;
uint8_t Start_Offset_EjectionIn_Timer;
uint8_t Start_Offset_Ejectionout_Timer;

uint16_t Production;

void Auto_business_logic(const Hw_Inputs);
void Manual_business_logic(const Hw_Inputs);

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
	input.MotorOn_Switch 			=	HAL_GPIO_ReadPin(GPIOB,MotorON_Switch_Pin);
	if(input.MotorOn_Switch == GPIO_PIN_SET){
		Inputs_Status = Inputs_Status & ~(1 << 11);

	}else{
		Inputs_Status = Inputs_Status |(1 <<11);
	}
	input.MotorOff_Switch 			=	HAL_GPIO_ReadPin(GPIOB,MotorOff_Switch_Pin);
	if(input.MotorOff_Switch == GPIO_PIN_SET){
		Inputs_Status = Inputs_Status & ~(1 << 12);

	}else{
		Inputs_Status = Inputs_Status |(1 <<12);
	}
	input.Station_Conformation 			=	HAL_GPIO_ReadPin(GPIOA,StationInfo_Sensor_Pin);
	if(input.Station_Conformation == GPIO_PIN_SET){
		Inputs_Status = Inputs_Status & ~(1 << 13);

	}else{
		Inputs_Status = Inputs_Status |(1 <<13);
	}
	input.Robo_Acknowledgment 			=	HAL_GPIO_ReadPin(GPIOA,Robo_Ack_Input_Pin);
	if(input.Robo_Acknowledgment == GPIO_PIN_SET){
		Inputs_Status = Inputs_Status & ~(1 << 14);

	}else{
		Inputs_Status = Inputs_Status |(1 <<14);
	}
	input.Ram_Open_Sensor 			=	HAL_GPIO_ReadPin(GPIOC,Rampopen_sensor_Pin);
	if(input.Ram_Open_Sensor == GPIO_PIN_SET){
		Inputs_Status = Inputs_Status & ~(1 << 15);

	}else{
		Inputs_Status = Inputs_Status |(1 <<15);
	}
	input.Ram_Close_Sensor 			=	HAL_GPIO_ReadPin(GPIOC,Rampclose_sensor_Pin);
	if(input.Ram_Close_Sensor == GPIO_PIN_SET){
		Inputs_Status_2 = Inputs_Status_2 & ~(1 << 0);

	}else{
		Inputs_Status_2 = Inputs_Status_2 |(1 <<0);
	}
	input.TiltingUp_Sensor			=	HAL_GPIO_ReadPin(GPIOA,TiltingUp_Sensor_Pin);
	if(input.TiltingUp_Sensor == GPIO_PIN_SET){
		Inputs_Status_2 = Inputs_Status_2 & ~(1 << 1);

	}else{
		Inputs_Status_2 = Inputs_Status_2 |(1 <<1);
	}
	input.TiltingDown_Sensor 		=	HAL_GPIO_ReadPin(GPIOA,Tiltingdown_sensor_Pin);
	if(input.TiltingDown_Sensor == GPIO_PIN_SET){
		Inputs_Status_2 = Inputs_Status_2 & ~(1 << 2);

		}else{
			Inputs_Status_2 = Inputs_Status_2 |(1 <<2);
		}
	if(input.Auto_Manual == GPIO_PIN_SET){//execute auto code
		Auto_business_logic(input);
	}
	else{//execute manual code
		Manual_business_logic(input);
	}

//Update the output status:
	output.Ram_Close_Valve 		=	HAL_GPIO_ReadPin(GPIOD,RampCLose_valve_Pin);
	if(output.Ram_Close_Valve == GPIO_PIN_SET){
		Inputs_Status_2 = Inputs_Status_2 & ~(1 << 6);
		}else{
		Inputs_Status_2 = Inputs_Status_2 |(1 <<6);}
	output.Ram_Open_Valve 		=	HAL_GPIO_ReadPin(GPIOD,RampOpen_valve_Pin);
	if(output.Ram_Open_Valve == GPIO_PIN_SET){
		Inputs_Status_2 = Inputs_Status_2 & ~(1 << 7);
		}else{
		Inputs_Status_2 = Inputs_Status_2 |(1 <<7);}
	output.Tilting_Up_Valve 		=	HAL_GPIO_ReadPin(GPIOD,TiltingUp_valve_Pin);
		if(output.Tilting_Up_Valve == GPIO_PIN_SET){
			Inputs_Status_2 = Inputs_Status_2 & ~(1 << 8);
		}else{
			Inputs_Status_2 = Inputs_Status_2 |(1 <<8);}
	output.Tilting_Down_Valve		=	HAL_GPIO_ReadPin(GPIOD,TiltingDown_valve_Pin);
		if(output.Tilting_Down_Valve == GPIO_PIN_SET){
			Inputs_Status_2 = Inputs_Status_2 & ~(1 << 9);
		}else{
			Inputs_Status_2 = Inputs_Status_2 |(1 <<9);}
	output.Slider_In_Valve		=	HAL_GPIO_ReadPin(GPIOD,SliderIn_valve_Pin);
		if(output.Slider_In_Valve == GPIO_PIN_SET){
			Inputs_Status_2 = Inputs_Status_2 & ~(1 << 10);
		}else{
			Inputs_Status_2 = Inputs_Status_2 |(1 <<10);}
	output.Slider_Out_Valve		=	HAL_GPIO_ReadPin(GPIOD,SkiderOut_valve_Pin);
		if(output.Slider_Out_Valve == GPIO_PIN_SET){
			Inputs_Status_2 = Inputs_Status_2 & ~(1 << 11);
		}else{
			Inputs_Status_2 = Inputs_Status_2 |(1 <<11);}
	output.Ejection_In_Valve 		=	HAL_GPIO_ReadPin(GPIOC,EjectionOn_valve_Pin);
		if(output.Ejection_In_Valve == GPIO_PIN_SET){
			Inputs_Status_2 = Inputs_Status_2 & ~(1 << 12);
		}else{
			Inputs_Status_2 = Inputs_Status_2 |(1 <<12);}
	output.Ejection_Out_Valve 		=	HAL_GPIO_ReadPin(GPIOC,EjectionOff_valve_Pin);
		if(output.Ejection_Out_Valve == GPIO_PIN_SET){
			Inputs_Status_2 = Inputs_Status_2 & ~(1 << 13);
		}else{
			Inputs_Status_2 = Inputs_Status_2 |(1 <<13);}
	output.Motor_On_Off_valve 		=	HAL_GPIO_ReadPin(GPIOD,MotorOn_valve_Pin);
		if(output.Motor_On_Off_valve == GPIO_PIN_SET){
			Inputs_Status_2 = Inputs_Status_2 & ~(1 << 14);
		}else{
			Inputs_Status_2 = Inputs_Status_2 |(1 <<14);}
	output.Robo_Status_Valve 		=	GPIO_PIN_SET;
		if(output.Robo_Status_Valve == GPIO_PIN_SET){
			Inputs_Status_2 = Inputs_Status_2 & ~(1 << 15);
		}else{
			Inputs_Status_2 = Inputs_Status_2 |(1 <<15);}
}


void Auto_business_logic(const Hw_Inputs input_status)
{
	switch(current_state_auto)
	{
		case 0://wait for cycle start
			current_state_auto=0;
			if(input_status.cycleStart == GPIO_PIN_RESET){
				current_state_auto=1;
			}
		break;
		case 1:
			if(SLIDERVALVE){
				HAL_GPIO_WritePin(GPIOD,RampOpen_valve_Pin,GPIO_PIN_SET);
				Start_Offset_Slider_Timer = 1;
				current_state_auto=2;
			}
			else
			{
				current_state_auto=3;
			}
		break;
		case 2://Offset timer for slider valve
			if(Complete_Offset_Timer_Slider==1)
			{
				Complete_Offset_Timer_Slider=0;
				current_state_auto=3;
			}
			if(SLIDERVALVE==0){
				current_state_auto=3;
			}
		break;
		case 3://Check preconditions ramp close
			if((input_status.Ram_Close_Sensor== GPIO_PIN_SET)&&(input_status.Ram_Open_Sensor == GPIO_PIN_RESET))
			{
				HAL_GPIO_WritePin(GPIOD,RampCLose_valve_Pin,GPIO_PIN_SET);
				current_state_auto=4;
				Start_Offset_RampClose_Timer=1;
			}
		break;
		case 4:
			if(Complete_Offset_RampClose_Timer==1)
			{
				Complete_Offset_RampClose_Timer=0;
				current_state_auto=5;
			}
		break;
		case 5://Tilting up pre-condiion
			HAL_GPIO_WritePin(GPIOD,TiltingUp_valve_Pin,GPIO_PIN_SET);
			Start_Offset_Tiltingup_Timer=1;
			current_state_auto=6;
		break;
		case 6:
			if(Complete_Offset_Tiltingup_Timer==1)
			{
				Complete_Offset_Tiltingup_Timer=0;
				current_state_auto=7;
			}
		break;
		case 7://Wait for Pouring Robo or timer
			if(ROBOAUTOMATIC)
			{
				current_state_auto=9;
			}
			else
			{
				Start_Hold_Pouringwait_Timer=1;
				current_state_auto=8;
			}
		break;
		case 8:
			if(Complete_Hold_Pouringwait_Timer==1)
			{
				Complete_Hold_Pouringwait_Timer=0;
				current_state_auto=9;
			}
		break;
		case 9:
			HAL_GPIO_WritePin(GPIOD,TiltingUp_valve_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOD,TiltingDown_valve_Pin,GPIO_PIN_SET);
			Start_Offset_Tilting_Timer =1;
			current_state_auto=10;
		break;
		case 10:
			if(Complete_Offset_Tilting_Timer==1)
			{
				Complete_Offset_Tilting_Timer=0;
				current_state_auto=11;
			}
		break;
		case 11:
			Start_Hold_Curing_Timer=1;
			current_state_auto=12;
		break;
		case 12:
			if(Complete_Hold_Curing_Timer==1)
			{
				Complete_Hold_Curing_Timer=0;
				current_state_auto=13;
			}
		break;
		case 13://Ramp open
			HAL_GPIO_WritePin(GPIOD,RampOpen_valve_Pin,GPIO_PIN_SET);
			Start_Offset_Rampopen_Timer=1;
			current_state_auto=14;
		break;
		case 14:
			if(Complete_Offset_Rampopen_Timer==1)
			{
				Complete_Offset_Rampopen_Timer=0;
				current_state_auto=15;
			}
		break;
		case 15:
			if(SLIDERVALVE){
				HAL_GPIO_WritePin(GPIOD,SkiderOut_valve_Pin,GPIO_PIN_SET);
				Start_Offset_Sliderout_Timer=1;
				current_state_auto=16;
			}
			else
			{
				current_state_auto=17;
			}
		break;
		case 16:
			if(Complete_Offset_Sliderout_Timer==1)
			{
				Complete_Offset_Sliderout_Timer=0;
				current_state_auto=17;
			}
		break;
		case 17:
			HAL_GPIO_WritePin(GPIOC,EjectionOn_valve_Pin,GPIO_PIN_SET);
			Start_Offset_EjectionIn_Timer=1;
			current_state_auto=18;
		break;
		case 18:
			if(Complete_Offset_EjectionIn_Timer==1)
			{
				Complete_Offset_EjectionIn_Timer=0;
				current_state_auto=19;
			}
		break;
		case 19:
			HAL_GPIO_WritePin(GPIOC,EjectionOff_valve_Pin,GPIO_PIN_SET);
			Start_Offset_Ejectionout_Timer=1;
			current_state_auto=20;
		break;
		case 20:
			if(Complete_Offset_Ejectionout_Timer==1)
			{
				Complete_Offset_Ejectionout_Timer=0;
				current_state_auto=21;
			}
		break;
		case 21:
			Production = Production+1;
			current_state_auto=0;
		break;
		default:
			current_state_auto=0;
		break;
	}
}

void Manual_business_logic(const Hw_Inputs input_status)
{
	if(input_status.Ram_Open_Switch == GPIO_PIN_RESET){
		HAL_GPIO_WritePin(GPIOD,RampOpen_valve_Pin,GPIO_PIN_SET);
	}
}
