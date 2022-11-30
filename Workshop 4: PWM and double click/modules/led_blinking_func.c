#include "led_blinking_func.h"
//----------------------------------------------


int leds_indx(int a)
{
    switch (a)
    {
    case 1:
        return LED1;
        break;
    case 2:
        return LED_R;
        break;
    case 3:
        return LED_G;
        break;
    case 4:
        return LED_B;
        break;
    default:
        return 0;
        break;
    }
}
void led_on(int pin)
{
    nrf_gpio_pin_write(leds_indx(pin), LEDS_ACTIVE_STATE ? 1 : 0);
}

void led_off(int pin)
{
    nrf_gpio_pin_write(leds_indx(pin), LEDS_ACTIVE_STATE ? 0 : 1);
}

void leds_off(void)
{
    for (int i = 1; i <= LEDS_NUMBER; i++)
    {
        led_off(i);
    }
}

void init_board_leds(void)
{
    for (int i = 1; i <= LEDS_NUMBER; i++)
    {
        nrf_gpio_cfg_output(leds_indx(i));
    }
    leds_off();
}


int led_blinking_times(int i)
{
    int led1 = DEVICE_ID / 1000;
    int led2 = (DEVICE_ID % 1000) / 100;
    int led3 = ((DEVICE_ID % 1000) % 100) / 10;
    int led4 = ((DEVICE_ID % 1000) % 100) % 10;
    if (i == 1)
    {
        return led1;
    }
    else if (i == 2)
    {
        return led2;
    }
    else if (i == 3)
    {
        return led3;
    }
    else if (i == 4)
    {
        return led4;
    }
    else
    {
        return 0;
    }
}

void led_blink(int led_indx, int delay)
{
    led_on(led_indx);
    nrf_delay_ms(delay);
    led_off(led_indx);
    nrf_delay_ms(delay);
}






