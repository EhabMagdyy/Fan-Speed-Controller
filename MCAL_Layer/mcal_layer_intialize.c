/* 
 * File:   mcal_layer_intialize.c
 * Author: Ehab
 *
 * Created on 27 ?????, 2023, 10:24 ?
 */

#include "mcal_layer_intialize.h"

/* ADC Configuration */
adc_config_t adc = {
    .aquisition_time = ADC_12_TAD,
    .conversion_clock = ADC_FOSC_DIV_16,
    .channel = ANALOG_CHANNEL_AN0,
    .format_justification = REAULT_FORAMT_RIGHT_JUSTIFIED,
    .voltage_refrence = DISABLE_VOLTAGE_REFERENCE
};

/* PWM Configuration */
pwm_t pwm = {
    .pwm_frequency = 5000,
    .timer2_postscaler_value = CCP1_TIMER2_POSTSCALER_DIV_1,
    .timer2_prescaler_value = CCP1_TIMER2_PRESCALER_DIV_1
};

/* Timer2 Configuration */
timer2_t timer2 = {
    .postscaler_value = TIMER2_POSTSCALER_DIV_1,
    .prescaler_value = TIMER2_PRESCALER_DIV_1,
    .preload_value = 0
};


Std_ReturnType mcal_layer_int(void){
    Std_ReturnType ret = E_OK;
    
    ret = ADC_intialize(&adc);
    ret = CCP1_PWM_Intialize(&pwm);
    ret = timer2_intialize(&timer2);
    
    return ret;
}