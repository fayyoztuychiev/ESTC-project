#ifndef BUTTON_H_
#define BUTTON_H_
//------------------------------------------------
/*include files*/
#include "led_blinking_func.h"
//------------------------------------------------
extern volatile bool flag;
extern volatile bool double_click;

#define BUTTON NRF_GPIO_PIN_MAP(1, 6)

APP_TIMER_DEF(m_debouncing_timer_id);
//-----------------------------------------------------
void init_board_button(void);
void gpiote_init(void);
void button_event_handler(nrfx_gpiote_pin_t pin, nrf_gpiote_polarity_t action);
void lfclk_config(void);
void debouncing_timer_handler(void *p_context);
void create_timers();
//-------------------------------------------------
#endif
