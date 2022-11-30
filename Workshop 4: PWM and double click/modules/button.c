#include "button.h"

volatile bool flag;
volatile bool double_click;
bool debouncing;
int toggles = 0;

void init_board_button(void)
{
    nrf_gpio_cfg_input(BUTTON, NRF_GPIO_PIN_PULLUP);
}

void debouncing_timer_handler(void *p_context)
{
    debouncing = false;

    if (!nrf_gpio_pin_read(BUTTON))
    {
        flag = true;
    }
    else
    {
        flag = false;
    }

    toggles++;
    
    if (toggles == 4)
    {
        toggles = 0;
        double_click = !double_click;
    } 
    
    
}

void button_event_handler(nrfx_gpiote_pin_t pin, nrf_gpiote_polarity_t action)
{
    if (!debouncing)
    {
        debouncing = true;
        app_timer_start(m_debouncing_timer_id, APP_TIMER_TICKS(50), NULL);
    }
    // защита от дребезга
}

void gpiote_init(void)
{
    ret_code_t err_code;
    err_code = nrfx_gpiote_init();
    APP_ERROR_CHECK(err_code);

    nrfx_gpiote_in_config_t gpiote_init_in_config = NRFX_GPIOTE_CONFIG_IN_SENSE_TOGGLE(true);
    gpiote_init_in_config.pull = NRF_GPIO_PIN_PULLUP;

    err_code = nrfx_gpiote_in_init(BUTTON, &gpiote_init_in_config, button_event_handler);
    APP_ERROR_CHECK(err_code);

    nrfx_gpiote_in_event_enable(BUTTON, true);
}

void lfclk_config(void)
{
    ret_code_t err_code = nrf_drv_clock_init();
    APP_ERROR_CHECK(err_code);
    nrf_drv_clock_lfclk_request(NULL);
}

void create_timers()
{
    ret_code_t err_code;
    err_code = app_timer_create(&m_debouncing_timer_id, APP_TIMER_MODE_SINGLE_SHOT, debouncing_timer_handler);
    APP_ERROR_CHECK(err_code);
}
