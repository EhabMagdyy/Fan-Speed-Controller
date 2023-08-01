/* 
 * File:   ecu_dc_motor.h
 * Author: Ehab
 *
 * Created on 27 ?????, 2023, 10:30 ?
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H


/* Section: Includes */
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/* Section: Macro Declarations */
#define MOTOR_OFF 0x00
#define MOTOR_ON  0x01

#define MOTOR_PIN_1  0x00
#define MOTOR_PIN_2  0x01

/* Section: Macro Function Declarations */

/* Data Types Declarations */
typedef struct{
    pin_config_t motor_pin[2];
}motor_t;

/* Function Declarations */
Std_ReturnType motor_intialize(const motor_t* motor);
Std_ReturnType motor_move(const motor_t* motor);

#endif	/* ECU_DC_MOTOR_H */

