#include <stdbool.h>
#include <stdint.h>
#include "nrf_delay.h"
#include "nrf_gpio.h"

#define device_ID 7245
#define LEDS_NUMBER 4
#define leds_state 0

#define LED1 NRF_GPIO_PIN_MAP(0, 6)
#define LED_R NRF_GPIO_PIN_MAP(0, 8)
#define LED_G NRF_GPIO_PIN_MAP(1, 9)
#define LED_B NRF_GPIO_PIN_MAP(0, 12)

#define BUTTON NRF_GPIO_PIN_MAP(1, 6)


int leds(int a)
{
    if (a == 1)
    {
        return LED1;
    }
    else if (a == 2)
    {
        return LED_R;
    }
    else if (a == 3)
    {
        return LED_G;
    }
    else if (a == 4)
    {
        return LED_B;
    }
    else
    {
        return 0;
    }
}

void led_on(int pin)
{
    nrf_gpio_pin_write(leds(pin), leds_state ? 1 : 0);
}

void led_off(int pin)
{
    nrf_gpio_pin_write(leds(pin), leds_state ? 0 : 1);
}

void leds_off()
{
    for (int i = 1; i < 5; i++)
    {
        led_off(i);
    }
}

void init_board_leds()
{
    for (int i = 1; i <= 4; i++)
    {
        nrf_gpio_cfg_output(leds(i));
    }
    leds_off();
}

int led_blinking_times(int i)
{
    int led1 = device_ID / 1000;
    int led2 = (device_ID % 1000) / 100;
    int led3 = ((device_ID % 1000) % 100) / 10;
    int led4 = ((device_ID % 1000) % 100) % 10;
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

void led_blinking(int a)
{
    bool flag = false;
    for (int i = 1; i <= led_blinking_times(a); i++)
    {
        if (!nrf_gpio_pin_read(BUTTON)) 
        {
            led_on(a);
            flag = true;
            
        } 
        else
        {
            i--;
            flag = false;
        }
        nrf_delay_ms(500);
        if (!nrf_gpio_pin_read(BUTTON) && flag == true) 
        {            
            led_off(a);
        } 
        nrf_delay_ms(500);
    }
}

/**
 * @brief Function for application main entry.
 */
int main(void)
{
    /* Configure board. */
    // bsp_board_init(BSP_INIT_LEDS);
    init_board_leds();
    nrf_gpio_cfg_input(BUTTON, NRF_GPIO_PIN_PULLUP);
    /* Toggle LEDs. */
    while (true)
    {
        for (int i = 1; i <= LEDS_NUMBER; i++)
        {
                led_blinking(i);
                nrf_delay_ms(1000);
        }
    }
}

/**
 *@}
 **/
