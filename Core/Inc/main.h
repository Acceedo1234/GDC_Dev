/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Robo_Ack_Input_Pin GPIO_PIN_0
#define Robo_Ack_Input_GPIO_Port GPIOA
#define StationInfo_Sensor_Pin GPIO_PIN_1
#define StationInfo_Sensor_GPIO_Port GPIOA
#define Tiltingdown_sensor_Pin GPIO_PIN_2
#define Tiltingdown_sensor_GPIO_Port GPIOA
#define _W25QXX_CS_PIN_Pin_Pin GPIO_PIN_4
#define _W25QXX_CS_PIN_Pin_GPIO_Port GPIOA
#define Rampclose_sensor_Pin GPIO_PIN_4
#define Rampclose_sensor_GPIO_Port GPIOC
#define Rampopen_sensor_Pin GPIO_PIN_5
#define Rampopen_sensor_GPIO_Port GPIOC
#define MotorOff_Switch_Pin GPIO_PIN_0
#define MotorOff_Switch_GPIO_Port GPIOB
#define MotorON_Switch_Pin GPIO_PIN_1
#define MotorON_Switch_GPIO_Port GPIOB
#define CycleStart_Switch_Pin GPIO_PIN_7
#define CycleStart_Switch_GPIO_Port GPIOE
#define SliderIn_Switch_Pin GPIO_PIN_8
#define SliderIn_Switch_GPIO_Port GPIOE
#define SliderOut_Switch_Pin GPIO_PIN_9
#define SliderOut_Switch_GPIO_Port GPIOE
#define EjectionOut_Switch_Pin GPIO_PIN_10
#define EjectionOut_Switch_GPIO_Port GPIOE
#define EjectionIn_Switch_Pin GPIO_PIN_11
#define EjectionIn_Switch_GPIO_Port GPIOE
#define TiltingDown_Switch_Pin GPIO_PIN_12
#define TiltingDown_Switch_GPIO_Port GPIOE
#define TiltingUp_Switch_Pin GPIO_PIN_13
#define TiltingUp_Switch_GPIO_Port GPIOE
#define RampClose_Switch_Pin GPIO_PIN_14
#define RampClose_Switch_GPIO_Port GPIOE
#define RampOpen_Switch_Pin GPIO_PIN_15
#define RampOpen_Switch_GPIO_Port GPIOE
#define Emergency_Switch_Pin GPIO_PIN_10
#define Emergency_Switch_GPIO_Port GPIOB
#define Auto_Manual_Switch_Pin GPIO_PIN_11
#define Auto_Manual_Switch_GPIO_Port GPIOB
#define MotorOn_valve_Pin GPIO_PIN_8
#define MotorOn_valve_GPIO_Port GPIOD
#define MotorOff_valve_Pin GPIO_PIN_9
#define MotorOff_valve_GPIO_Port GPIOD
#define RampOpen_valve_Pin GPIO_PIN_10
#define RampOpen_valve_GPIO_Port GPIOD
#define RampCLose_valve_Pin GPIO_PIN_11
#define RampCLose_valve_GPIO_Port GPIOD
#define TiltingUp_valve_Pin GPIO_PIN_12
#define TiltingUp_valve_GPIO_Port GPIOD
#define TiltingDown_valve_Pin GPIO_PIN_13
#define TiltingDown_valve_GPIO_Port GPIOD
#define SkiderOut_valve_Pin GPIO_PIN_14
#define SkiderOut_valve_GPIO_Port GPIOD
#define SliderIn_valve_Pin GPIO_PIN_15
#define SliderIn_valve_GPIO_Port GPIOD
#define EjectionOn_valve_Pin GPIO_PIN_6
#define EjectionOn_valve_GPIO_Port GPIOC
#define EjectionOff_valve_Pin GPIO_PIN_7
#define EjectionOff_valve_GPIO_Port GPIOC
#define RoboRelay_output_Pin GPIO_PIN_8
#define RoboRelay_output_GPIO_Port GPIOC
#define UART_485_Tx_2_Pin GPIO_PIN_5
#define UART_485_Tx_2_GPIO_Port GPIOD
#define USART_Rx_485_2_Pin GPIO_PIN_6
#define USART_Rx_485_2_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
