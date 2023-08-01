/* 
 * File:   ecu_layer_intialize.h
 * Author: Ehab
 *
 * Created on 27 ?????, 2023, 10:25 ?
 */

#ifndef ECU_LAYER_INTIALIZE_H
#define	ECU_LAYER_INTIALIZE_H

/* Section: Includes */
#include "DC_Motor/ecu_dc_motor.h"
#include "LCD/ecu_lcd.h"

/* Data Type Deceleration */
extern motor_t motor;
extern lcd_8bit_t lcd;

/* Function Deceleration */
Std_ReturnType ecu_layer_int(void);

#endif	/* ECU_LAYER_INTIALIZE_H */

