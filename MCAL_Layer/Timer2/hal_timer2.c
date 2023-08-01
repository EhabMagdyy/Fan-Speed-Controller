/* 
 * File:   hal_timer2.c
 * Author: Ehab
 *
 * Created on 27 ?????, 2023, 09:57 ?
 */

#include "hal_timer2.h"

static uint8 tmr2_preload_value; 

Std_ReturnType timer2_intialize(const timer2_t *_timer){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL != _timer){
        ret = E_OK;
        
        /* Disable Timer1 Module */
        TIMER2_MODULE_DISABLE();
        
        /* Set Prescaler Value */
        TIMER2_PRESCALER_WRITE_VALUE(_timer->prescaler_value);
        
        /* Set Postscaler Value */
        TIMER2_POSTSCALER_WRITE_VALUE(_timer->postscaler_value);
        
        /* Write preload value */
        TIMER2_WRITE_VALUE(_timer->preload_value);
        tmr2_preload_value = _timer->preload_value;
        
        /* Enable Timer1 Module */
        TIMER2_MODULE_ENABLE();
    }
    return ret;
}

Std_ReturnType timer2_deIntialize(const timer2_t *_timer){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL != _timer){
        ret = E_OK;
        /* Disable Timer0 Module */
        TIMER2_MODULE_DISABLE();
    }
    return ret;
}

Std_ReturnType timer2_write_value(const timer2_t *_timer, uint8 value){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL != _timer){
        ret = E_OK;
        TIMER2_WRITE_VALUE(value);
    }
    return ret;
}

Std_ReturnType timer2_read_value(const timer2_t *_timer, uint8 *value){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL != _timer && NULL != value){
        ret = E_OK;
        *value = TMR2;
    }
    return ret;
}
