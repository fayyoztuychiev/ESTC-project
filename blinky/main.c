/** @file
 *
 * @defgroup blinky_example_main main.c
 * @{
 * @ingroup blinky_example
 * @brief Blinky Example Application main file.
 *
 * This file contains the source code for a sample application to blink LEDs.
 *
 */

#include <stdbool.h>
#include <stdint.h>
#include "nrf_delay.h"
#include "boards.h"

#define device_ID 7203

int led_blinking_times (int i) {
    int led1 = device_ID / 1000;
    int led2 = (device_ID % 1000) / 100;
    int led3 = ((device_ID % 1000) % 100) / 10;
    int led4 = ((device_ID % 1000) % 100) % 10;
    if (i == 0) {
        return led1;
    } else if (i == 1) {
        return led2;
    } else if (i == 2) {
        return led3;
    } else if (i == 3) {
        return led4;
    } else {
        return 0;
    }
} 



void led_blinking (int a) {
    for (int i = 0; i < 2*led_blinking_times(a); i++) {
        bsp_board_led_invert(a);
        nrf_delay_ms(100);
    }
} 

/**
 * @brief Function for application main entry.
 */
int main(void)
{
    /* Configure board. */
    bsp_board_init(BSP_INIT_LEDS);

    /* Toggle LEDs. */
    while (true)
    {
        for (int i = 0; i < LEDS_NUMBER; i++)
        {
            led_blinking(i);
            nrf_delay_ms(1000);
        }
    }
}

/**
 *@}
 **/
