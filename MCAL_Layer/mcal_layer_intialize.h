/* 
 * File:   mcal_layer_intialize.h
 * Author: Ehab
 *
 * Created on 27 ?????, 2023, 10:24 ?
 */

#ifndef MCAL_LAYER_INTIALIZE_H
#define	MCAL_LAYER_INTIALIZE_H

/* Section: Includes */
#include "ADC/hal_adc.h"
#include "PWM/hal_pwm.h"
#include "Timer2/hal_timer2.h"

/* Data Type Deceleration */
extern adc_config_t adc;
extern pwm_t pwm;
extern timer2_t timer2;

/* Function Deceleration */
Std_ReturnType mcal_layer_int(void);


#endif	/* MCAL_LAYER_INTIALIZE_H */

