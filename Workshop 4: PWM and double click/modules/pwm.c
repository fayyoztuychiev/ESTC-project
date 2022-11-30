#include "pwm.h"

int val = 0;
bool dir = true;

void pwm(int led_indx, int duty_cycle)
{
    uint32_t pwm_period_us = (uint32_t)(US_SECOND / PWM_FREQUENCY_HZ);
    uint32_t t_on_us = (uint32_t)((pwm_period_us * duty_cycle) / 100);
    uint32_t t_off_us = pwm_period_us - t_on_us;

    nrfx_systick_state_t current_time_from_systick;

    nrfx_systick_get(&current_time_from_systick);
    while (!nrfx_systick_test(&current_time_from_systick, t_on_us))
    {
        led_on(led_indx);
    }
    nrfx_systick_get(&current_time_from_systick);
    while (!nrfx_systick_test(&current_time_from_systick, t_off_us))
    {
        led_off(led_indx);
    }
}

void smoothly_blinking_mode(int led_indx)
{
    
    for (int i = 0; i < 200; i++)
    {
        pwm(led_indx, val);
        if (double_click)
        {
            if (dir)
                val++;
            else
                val--;
            if (val == 100) dir = !dir;
            if (val == 0) 
            {
                dir = !dir;
                nrf_delay_ms(100);
            } 
        }
        else
        {
            i--;
        }
    }
}
