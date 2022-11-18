
#ifndef LED_BLINKING_FUNC_H_
#define LED_BLINKING_FUNC_H_
//------------------------------------------------
#include <stdbool.h>
#include <stdint.h>
#include "nrf_gpio.h"
#include "nrf_delay.h"
#include "nrfx_systick.h"
//------------------------------------------------

#define DEVICE_ID 1234
#define LEDS_NUMBER 4
#define LEDS_ACTIVE_STATE 0

#define LED1 NRF_GPIO_PIN_MAP(0, 6)
#define LED_R NRF_GPIO_PIN_MAP(0, 8)
#define LED_G NRF_GPIO_PIN_MAP(1, 9)
#define LED_B NRF_GPIO_PIN_MAP(0, 12)

#define BUTTON NRF_GPIO_PIN_MAP(1, 6)

//-------------------------------------------------

int  leds_indx(int a);
void led_on(int pin);
void led_off(int pin);
void leds_off();
void init_board_leds(void);
void init_board_button(void);
int  led_blinking_times(int i);
int check_board_button(void);
//------------------------------------------------
#endif 
