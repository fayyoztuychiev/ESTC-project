#ifndef LED_BLINKING_FUNC_H_
#define LED_BLINKING_FUNC_H_
//------------------------------------------------
#include <stdbool.h>
#include <stdint.h>
#include "nrf_gpio.h"
#include "nrf_delay.h"
#include "nrfx_systick.h"
#include "nrfx_gpiote.h"
#include "app_timer.h"
#include "app_error.h"
#include "nrf_drv_clock.h"
//------------------------------------------------

//------------------------------------------------
#define DEVICE_ID 7203
#define LEDS_NUMBER 4
#define LEDS_ACTIVE_STATE 0



#define LED1 NRF_GPIO_PIN_MAP(0, 6)
#define LED_R NRF_GPIO_PIN_MAP(0, 8)
#define LED_G NRF_GPIO_PIN_MAP(1, 9)
#define LED_B NRF_GPIO_PIN_MAP(0, 12)
//-------------------------------------------------
int  leds_indx(int a);
void led_on(int pin);
void led_off(int pin);
void leds_off();
void init_board_leds(void);

int  led_blinking_times(int i);

void led_blink(int led_indx, int delay);

//------------------------------------------------
#endif 
