/* 
 * File:   ecu_layer_intialize.c
 * Author: Ehab
 *
 * Created on 27 ?????, 2023, 10:25 ?
 */

#include "ecu_layer_intialize.h"

motor_t motor = {
    .motor_pin[0].port = PORTC_INDEX,
    .motor_pin[0].pin = GPIO_PIN0,
    .motor_pin[0].direction = GPIO_direction_output,
    .motor_pin[0].logic = GPIO_LOW,
    .motor_pin[1].port = PORTC_INDEX,
    .motor_pin[1].pin = GPIO_PIN1,
    .motor_pin[1].direction = GPIO_direction_output,
    .motor_pin[1].logic = GPIO_LOW
};

lcd_8bit_t lcd = {
    .lcd_rs.port = PORTC_INDEX,
    .lcd_rs.pin = GPIO_PIN6,
    .lcd_rs.direction = GPIO_direction_output,
    .lcd_rs.logic = GPIO_LOW,
    .lcd_enable.port = PORTC_INDEX,
    .lcd_enable.pin = GPIO_PIN7,
    .lcd_enable.direction = GPIO_direction_output,
    .lcd_enable.logic = GPIO_LOW,
    
    .data_lines[0].port = PORTD_INDEX,
    .data_lines[0].pin = GPIO_PIN0,
    .data_lines[0].direction = GPIO_direction_output,
    .data_lines[0].logic = GPIO_LOW,
    .data_lines[1].port = PORTD_INDEX,
    .data_lines[1].pin = GPIO_PIN1,
    .data_lines[1].direction = GPIO_direction_output,
    .data_lines[1].logic = GPIO_LOW,
    .data_lines[2].port = PORTD_INDEX,
    .data_lines[2].pin = GPIO_PIN2,
    .data_lines[2].direction = GPIO_direction_output,
    .data_lines[2].logic = GPIO_LOW,
    .data_lines[3].port = PORTD_INDEX,
    .data_lines[3].pin = GPIO_PIN3,
    .data_lines[3].direction = GPIO_direction_output,
    .data_lines[3].logic = GPIO_LOW,
    .data_lines[4].port = PORTD_INDEX,
    .data_lines[4].pin = GPIO_PIN4,
    .data_lines[4].direction = GPIO_direction_output,
    .data_lines[4].logic = GPIO_LOW,
    .data_lines[5].port = PORTD_INDEX,
    .data_lines[5].pin = GPIO_PIN5,
    .data_lines[5].direction = GPIO_direction_output,
    .data_lines[5].logic = GPIO_LOW,
    .data_lines[6].port = PORTD_INDEX,
    .data_lines[6].pin = GPIO_PIN6,
    .data_lines[6].direction = GPIO_direction_output,
    .data_lines[6].logic = GPIO_LOW,
    .data_lines[7].port = PORTD_INDEX,
    .data_lines[7].pin = GPIO_PIN7,
    .data_lines[7].direction = GPIO_direction_output,
    .data_lines[7].logic = GPIO_LOW
};

Std_ReturnType ecu_layer_int(void){
    Std_ReturnType ret = E_OK;
    
    ret = lcd_8bit_intialize(&lcd);
    ret = motor_intialize(&motor);
    
    return ret;
}