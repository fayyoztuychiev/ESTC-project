#include "led_blinking_func.h"
#include "button.h"
#include "pwm.h"

/**
 * @brief Function for application main entry.
 */

int main(void)
{
    init_board_leds();
    init_board_button();
    nrfx_systick_init();
    lfclk_config();
    gpiote_init();
    app_timer_init();
    create_timers();

    while (true)
    {
        for (int i = 1; i <= LEDS_NUMBER; i++)
        {
            for (int j = 1; j <= led_blinking_times(i); j++)
            {
                smoothly_blinking_mode(i);
                nrf_delay_ms(100);
            }
        }
    }
}

/**
 *@}
 **/

