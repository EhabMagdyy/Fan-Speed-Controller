/* 
 * File:   application.c
 * Author: Ehab
 * 
 * Fan speed controller with temperature
 * 
 * Created on 27, 7, 2023
 */

#include "application.h"

Std_ReturnType ret = E_OK;

uint16 lm35_value, lm35_value_in_celsuis;
uint8 lm35_value_text[4];

uint8 temperature_level;

int main()
{
    ret = application_intialize();
    
    ret = lcd_8bit_send_string(&lcd, "FAN OFF -Level  ");
    ret = lcd_8bit_send_string_pos(&lcd, 2, 4, "TEMP: ");
    ret = lcd_8bit_send_char_pos(&lcd, 2, 13, 'C');
    
    ret = motor_move(&motor);
    
    while(1)
    {
        /* Reading AD0 channel "Temperature sensor value" */
        ret = ADC_getConversionBlocking(&adc, ANALOG_CHANNEL_AN0, &lm35_value);
        
        /* Convert output of LM35 to Celsuis [(step_size = Vref/resolution) -> (5/2^10 = 4.88)] */
        lm35_value_in_celsuis = lm35_value * 4.88f;
        lm35_value_in_celsuis = round(lm35_value_in_celsuis / 10.0);
        
        /* Converting the number into string and Display the temperature on the screen */
        ret = lcd_convert_byte_to_string(lm35_value_in_celsuis, lm35_value_text);
        ret = lcd_8bit_send_string_pos(&lcd, 2, 10, lm35_value_text);
        
        /* Setting duty cycle to control the speed of fan with respect to temperature value */
        if(lm35_value_in_celsuis > 120){
            temperature_level = '5';
            ret = CCP1_PWM_Set_Duty(100);
        }
        else if(lm35_value_in_celsuis > 90){
            temperature_level = '4';
            ret = CCP1_PWM_Set_Duty(80);
        }
        else if(lm35_value_in_celsuis > 70){
            temperature_level = '3';
            ret = CCP1_PWM_Set_Duty(60);
        }
        else if(lm35_value_in_celsuis > 50){
            temperature_level = '2';
            ret = CCP1_PWM_Set_Duty(40);
        }
        else if(lm35_value_in_celsuis > 25){
            temperature_level = '1';
            ret = CCP1_PWM_Set_Duty(20);
        }
        else{
            temperature_level = '0';
            ret = CCP1_PWM_Set_Duty(0);
            ret = lcd_8bit_send_string_pos(&lcd, 1, 5, "OFF");
        }
        if('0' != temperature_level){
            ret = lcd_8bit_send_string_pos(&lcd, 1, 5, "ON ");
        }
        /* Displaying Temperature level */
        ret = lcd_8bit_send_char_pos(&lcd, 1, 16, temperature_level);
    }
    return (EXIT_SUCCESS);
}

Std_ReturnType application_intialize(){
    Std_ReturnType ret = E_OK;
    
    ret = ecu_layer_int();
    ret = mcal_layer_int();
    
    return ret;
}