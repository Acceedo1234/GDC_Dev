/*
 * TimerInt.h
 *
 *  Created on: Aug 26, 2023
 *      Author: DINESH
 */

#ifndef INTERRUPTHANDLER_TIMERINT_H_
#define INTERRUPTHANDLER_TIMERINT_H_

extern void TimerApplicationInit(void);
extern void InputOutputTest(void);
extern uint8_t Flag1Sec;
extern uint8_t Flag5msTM2;
extern uint8_t Flag200ms;
extern uint8_t Flag500ms;

extern uint8_t Complete_Offset_Timer_Slider;
extern uint8_t Complete_Offset_RampClose_Timer;
extern uint8_t Complete_Offset_Tiltingup_Timer;
extern uint8_t Complete_Hold_Pouringwait_Timer;
extern uint8_t Complete_Offset_Tilting_Timer;
extern uint8_t Complete_Hold_Curing_Timer;
extern uint8_t Complete_Offset_Rampopen_Timer;
extern uint8_t Complete_Offset_Sliderout_Timer;
extern uint8_t Complete_Offset_EjectionIn_Timer;
extern uint8_t Complete_Offset_Ejectionout_Timer;
#endif /* INTERRUPTHANDLER_TIMERINT_H_ */
