/**
 * @file pcf85263at.h
 * @author Nihal.KT (you@domain.com)
 * @brief This is the driver code for pc85263at rtc.
 * @version 0.1
 * @date 2024-01-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef __INC_PCF85263AT_DRIVER__
#define __INC_PCF85263AT_DRIVER__

#include <stdint.h>

/**
 * @brief Address of pcf85263at RTC
 * 
 */
#define RTC_ADDR	0x51 << 1

/**
 * ********************************************** 
 * @brief Time mode Registers
 * **********************************************
 */

/**
 * @brief Registers for seconds, min, hour (hh:mm:ss)
 * 
 */
#define RTC_REG_ADDR_SEC        0x01
#define RTC_REG_ADDR_MIN        0x02
#define RTC_REG_ADDR_HOUR       0x03

/**
 * @brief Registers for day, weekday, month, year
 * 
 */
#define RTC_REG_ADDR_DAY        0x04
#define RTC_REG_ADDR_WDAY       0x05
#define RTC_REG_ADDR_MONTH      0x06
#define RTC_REG_ADDR_YEAR       0x07

/**
 * @brief TODO: Add required brief note.
 * 
 */
#define RTC_REG_FN_REG          0x28

/**
 * ********************************************** 
 * @brief Alarm mode Registers
 * **********************************************
 */

/**
 * @brief Alarm (1 and 2) enable register
 * *************************************
 * @attention   
 * 
 * ******************************
 * 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0
 * *****************************
 * 7 - 5 Alarm 2
 * 4 - 0 Alarm 1
 * 
 */
#define RTC_REG_ALM_ENABLE_CR	0x10

/**
 * @brief Alarm 2 Enable registers
 * 
 */
#define WDAY_A2E					1 << 7
#define HR_A2E						1 << 6
#define MIN_A2E						1 << 5

/**
 * @brief Alarm 2 value store registers
 * 
 */
#define SLC_RTC_REG_ADDR_MIN_ALM2	0x0D
#define SLC_RTC_REG_ADDR_HR_ALM2	0x0E
#define SLC_RTC_REG_ADDR_DAY_ALM2	0x0F

/**
 * @brief Alarm 1 Enable registers
 * 
 */
#define MON_A1E						1 << 4
#define DAY_A1E						1 << 3
#define HR_A1E						1 << 2
#define MIN_A1E						1 << 1
#define SEC_A1E						1 << 0

/**
 * @brief Alarm 1 value store registers
 * 
 */
#define SLC_RTC_REG_ADDR_SEC_ALM1	0x08
#define SLC_RTC_REG_ADDR_MIN_ALM1	0x09
#define SLC_RTC_REG_ADDR_HR_ALM1	0x0A
#define SLC_RTC_REG_ADDR_DAY_ALM1	0x0B
#define SLC_RTC_REG_ADDR_MNTH_ALM1	0X0C

/**
 * @brief enum holding the values forrtc registers
 * 
 */
typedef enum _rtc_reg_sel
{
    RTC_REG_SEL_SEC = 0,
    RTC_REG_SEL_MIN,
    RTC_REG_SEL_HOUR,
    RTC_REG_SEL_DAY,
    RTC_REG_SEL_WDAY,
    RTC_REG_SEL_MONTH,
    RTC_REG_SEL_YEAR,
    RTC_REG_SEL_FNREG,

	// Alm enable
	RTC_REG_SEL_ALM_EN,

	// Alm1
	RTC_REG_SEL_ALM1_SEC,
	RTC_REG_SEL_ALM1_MIN,
	RTC_REG_SEL_ALM1_HR,
	RTC_REG_SEL_ALm1_DAY,
	RTC_REG_SEL_ALM1_MNTH,

	// Alm2
	RTC_REG_SEL_AlM2_MIN,
	RTC_REG_SEL_AlM2_HR,
	RTC_REG_SEL_AlM2_DAY,
}
rtc_reg_sel_t;

/**
 * @brief Get the rtc device address macro
 * 
 * @return uint8_t 
 */
extern uint8_t get_rtc_device_address(void);

/**
 * @brief Get the rtc register address 
 * 
 * @param rtc_reg 
 * @return uint8_t 
 */
extern uint8_t get_rtc_register_address(rtc_reg_sel_t rtc_reg);

#endif /* __INC_PCF85263AT_DRIVER__ */