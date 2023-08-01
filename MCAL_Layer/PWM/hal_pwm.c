/* 
 * File:   hal_pwm.c
 * Author: Ehab
 *
 * Created on 27 ?????, 2023, 09:56 ?
 */


#include "hal_pwm.h"

Std_ReturnType CCP1_PWM_Intialize(const pwm_t *pwm)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL != pwm){
        ret = E_OK;
        
        /* Disable CCP1 mode */
        CCP1_SELECT_MODE(CCP1_MODULE_DISABLE);

        /* Clearing CCP1 bit <output> */
        TRISCbits.RC2 = 0;
        
        /* Write Period value */
        PR2 = (uint8)((_XTAL_FREQ / ((uint32)4 * (pwm->pwm_frequency) * 
                     (pwm->timer2_postscaler_value) * (pwm->timer2_prescaler_value))) - 1);
        
        /* Enable CCP1 In PWM Mode */
        CCP1_SELECT_MODE(CCP1_PWM_MODE); 
    }
    return ret;
}

Std_ReturnType CCP1_PWM_Set_Duty(uint8 duty){
    Std_ReturnType ret = E_NOT_OK;
    
    if(100 >= duty)
    {
        ret = E_OK;
        /* because the output duty cycle is inverted, and i don't know why yet */
        duty = 100 - duty;  /* So i write this line to get a correct output duty */
        
        uint16 duty_cycle = (uint16)((PR2 + 1) * (duty / 100.0) * 4);
        
        CCP1CONbits.DC1B = (uint8)(duty_cycle & 0x03);
        CCPR1L = (uint8)(duty_cycle >> 2);
    }
    
    return ret;
}
