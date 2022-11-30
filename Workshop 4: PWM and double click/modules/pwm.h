#ifndef PWM_H_
#define PWM_H_
//-----------------------------------------
#include "led_blinking_func.h"
#include "button.h"
//-----------------------------------------
#define PWM_FREQUENCY_HZ 1000
#define US_SECOND 1000000

void pwm (int led_indx, int duty_cycle);
void smoothly_blinking_mode(int led_indx);

//-----------------------------------------
#endif
