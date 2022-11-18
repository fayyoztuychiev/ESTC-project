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

#include "modules/led_blinking_func.h"
#include "nrf_delay.h"


/**
 * @brief Function for application main entry.
 */
int main(void)
{

    init_board_leds();
    init_board_button();

    /* Toggle LEDs. */
    while (true)
    {
        for (int i = 1; i <= LEDS_NUMBER; i++)
        {
            for (int j = 1; j <= led_blinking_times(i); j++)
            {
                bool led_current_state = false;
                if (check_board_button() && led_current_state == false)
                {
                    led_on(i);
                    led_current_state = true;
                    nrf_delay_ms(500);
                }
                                
                if (check_board_button() && led_current_state == true)
                {
                    led_off(i);
                    led_current_state = false;
                    nrf_delay_ms(500);
                }
                else 
                {
                    j--;
                }
                
            }
            nrf_delay_ms(500);
        }
    }
}

/**
 *@}
 **/
