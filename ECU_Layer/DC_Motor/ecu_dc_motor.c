/* 
 * File:   ecu_dc_motor.c
 * Author: Ehab
 *
 * Created on 27 ?????, 2023, 10:30 ?
 */

#include "ecu_dc_motor.h"

Std_ReturnType motor_intialize(const motor_t* motor){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL != motor){
        ret = E_OK;
        ret = gpio_pin_intialize(&motor->motor_pin[MOTOR_PIN_1]);
        ret = gpio_pin_intialize(&motor->motor_pin[MOTOR_PIN_2]);
    }
    return ret;
}

Std_ReturnType motor_move(const motor_t* motor){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL != motor){
        ret = E_OK;
        ret = gpio_pin_write_logic(&motor->motor_pin[MOTOR_PIN_1], GPIO_HIGH);
        ret = gpio_pin_write_logic(&motor->motor_pin[MOTOR_PIN_2], GPIO_LOW);
    }
    return ret;
}
