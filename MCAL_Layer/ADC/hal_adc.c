/* 
 * File:   hal_adc.c
 * Author: Ehab
 *
 * Created on 27 ?????, 2023, 09:54 ?
 */

#include "hal_adc.h"

static Std_ReturnType ADC_Configure_Channel_pin(const adc_analog_channel_t channel);

/**
 * 
 * @param _adc
 * @return 
 */
Std_ReturnType ADC_intialize(const adc_config_t *_adc)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL != _adc){
        ret = E_OK;
        /* Disable ADC Module */
        ADC_MODULE_DISABLE();
        
        /* configure the acquisition time */
        ADC_SELECT_ACQUISITION_TIME(_adc->aquisition_time);
        
        /* configure the acquisition time */
        ADC_SELECT_CONVERSION_CLOCK(_adc->conversion_clock);
        
        /* configure voltage reference */
        if(ENABLE_VOLTAGE_REFERENCE == _adc->voltage_refrence){
            ADC_ENABLE_VOLTAGE_REFERENCE();
        }
        else{
            ADC_DISABLE_VOLTAGE_REFERENCE();
        }
        
        /* configure format */
        if(REAULT_FORAMT_LEFT_JUSTIFIED == _adc->format_justification){
            ADC_REAULT_FORAMT_LEFT_JUSTIFIED();
        }
        else{
            ADC_REAULT_FORAMT_RIGHT_JUSTIFIED();
        }
        
        /* select channel & set channel pin(input) */
        ADC_SELECT_CHANNEL(_adc->channel);
        ret = ADC_Configure_Channel_pin(_adc->channel);
        
        /* Enable ADC Module */
        ADC_MODULE_ENABLE();
    }
    return ret;
}

/**
 * 
 * @param _adc
 * @param channel
 * @return 
 */
Std_ReturnType ADC_selectChannel(const adc_config_t *_adc, adc_analog_channel_t channel)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL != _adc){
        ret = E_OK;
        /* select channel & set channel pin(input) */
        ADC_SELECT_CHANNEL(channel);
        ret = ADC_Configure_Channel_pin(channel);
    }
    return ret;
}

/**
 * 
 * @param _adc
 * @return 
 */
Std_ReturnType ADC_startConversion(const adc_config_t *_adc){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL != _adc){
        ret = E_OK;
        /* Start Conversion process */
        ADC_START_CONVERSION();
    }
    return ret;
}

/**
 * 
 * @param _adc
 * @param result
 * @return 
 */
Std_ReturnType ADC_getConversionResult(const adc_config_t *_adc, converion_result_t *result)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL != _adc && NULL != result){
        ret = E_OK;
        if(REAULT_FORAMT_RIGHT_JUSTIFIED == _adc->format_justification){
            *result = (converion_result_t)(ADRESL + (ADRESH << 8)); 
        }
        else if(REAULT_FORAMT_LEFT_JUSTIFIED == _adc->format_justification){
            *result = (converion_result_t)((ADRESL >> 6) + (ADRESH << 2)); 
        }
        else{
            *result = 0;
            ret = E_NOT_OK;
        }
    }
    return ret;
}

/**
 * 
 * @param _adc
 * @param channel
 * @param result
 * @return 
 */
Std_ReturnType ADC_getConversionBlocking(const adc_config_t *_adc, adc_analog_channel_t channel
                                     , converion_result_t *result)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL != _adc && NULL != result){
        ret = E_OK;
        /* Select input channel */
        ret &= ADC_selectChannel(_adc, channel);
        /* Start conversion process */
        ret &= ADC_startConversion(_adc);
        /* Wait until conversion is done */
        while(ADCON0bits.GO_nDONE);
        /* Get result */
        ret &= ADC_getConversionResult(_adc, result);
    }
    return ret;
}

/**
 * Configure Channel pin as input
 */
static Std_ReturnType ADC_Configure_Channel_pin(const adc_analog_channel_t channel)
{
    Std_ReturnType ret = E_OK;
    switch(channel){
        case ANALOG_CHANNEL_AN0: SET_BIT(TRISA, _TRISA_RA0_POSN); break;
        case ANALOG_CHANNEL_AN1: SET_BIT(TRISA, _TRISA_RA1_POSN); break;
        case ANALOG_CHANNEL_AN2: SET_BIT(TRISA, _TRISA_RA2_POSN); break;
        case ANALOG_CHANNEL_AN3: SET_BIT(TRISA, _TRISA_RA3_POSN); break;
        case ANALOG_CHANNEL_AN4: SET_BIT(TRISA, _TRISA_RA5_POSN); break;
        case ANALOG_CHANNEL_AN5: SET_BIT(TRISE, _TRISE_RE0_POSN); break;
        case ANALOG_CHANNEL_AN6: SET_BIT(TRISE, _TRISE_RE1_POSN); break;
        case ANALOG_CHANNEL_AN7: SET_BIT(TRISE, _TRISE_RE2_POSN); break;
        case ANALOG_CHANNEL_AN8: SET_BIT(TRISB, _TRISB_RB2_POSN); break;
        case ANALOG_CHANNEL_AN9: SET_BIT(TRISB, _TRISB_RB3_POSN); break;
        case ANALOG_CHANNEL_AN10: SET_BIT(TRISB, _TRISB_RB1_POSN); break;
        case ANALOG_CHANNEL_AN11: SET_BIT(TRISB, _TRISB_RB4_POSN); break;
        case ANALOG_CHANNEL_AN12: SET_BIT(TRISB, _TRISB_RB0_POSN); break;
        default :  ret = E_NOT_OK;
    }
    return ret;
}
