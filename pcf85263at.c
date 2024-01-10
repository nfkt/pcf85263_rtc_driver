/**
 * @file pcf85263at.c
 * @author Nihal.KT (you@domain.com)
 * @brief pcf85263at implementation file
 * @version 0.1
 * @date 2024-01-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "pcf85263at.h"

uint8_t get_rtc_device_address(void)
{
    return RTC_ADDR;
}

uint8_t get_rtc_register_address(rtc_reg_sel_t rtc_reg)
{

    uint8_t rtc_reg_addr  = RTC_REG_SEL_SEC;     
    switch(rtc_reg)
    {
        case RTC_REG_SEL_SEC:   rtc_reg_addr = RTC_REG_ADDR_SEC;    break;
        case RTC_REG_SEL_MIN:   rtc_reg_addr = RTC_REG_ADDR_MIN;    break;
        case RTC_REG_SEL_HOUR:  rtc_reg_addr = RTC_REG_ADDR_HOUR;   break;

        case RTC_REG_SEL_DAY:   rtc_reg_addr = RTC_REG_ADDR_DAY;    break;

        // TODO: Complete the register address fill.
    }
}

