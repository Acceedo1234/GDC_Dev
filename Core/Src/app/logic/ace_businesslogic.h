/*
 * ace_businesslogic.h
 *
 *  Created on: 02-Oct-2023
 *      Author: MKS
 */

#ifndef SRC_APP_LOGIC_ACE_BUSINESSLOGIC_H_
#define SRC_APP_LOGIC_ACE_BUSINESSLOGIC_H_

extern void gdc_businesslogic(void);

extern uint16_t Inputs_Status,Inputs_Status_2;
extern uint16_t TIltingup;
extern uint16_t tinltingdown;
extern uint16_t CuringTime;
extern uint16_t sliderin;
extern uint16_t SLiderout;
extern uint16_t Ejectionon;
extern uint16_t Ejectionoff;

extern uint8_t Start_Offset_Slider_Timer;
extern uint8_t Start_Offset_RampClose_Timer;
extern uint8_t Start_Offset_Tiltingup_Timer;
extern uint8_t Start_Hold_Pouringwait_Timer;
extern uint8_t Start_Offset_Tilting_Timer;
extern uint8_t Start_Hold_Curing_Timer;
extern uint8_t Start_Offset_Rampopen_Timer;
extern uint8_t Start_Offset_Sliderout_Timer;
extern uint8_t Start_Offset_EjectionIn_Timer;
extern uint8_t Start_Offset_Ejectionout_Timer;

extern uint16_t Production;

#endif /* SRC_APP_LOGIC_ACE_BUSINESSLOGIC_H_ */
