/*
 * Copyright (c) 2016-2017, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/** ============================================================================
 *  @file       CC2640R2_LAUNCHXL.h
 *
 *  @brief      CC2640R2 LaunchPad Board Specific header file.
 *
 *  This file is responsible for setting up the board specific items for the
 *  CC2640R2_LAUNCHXL board.
 *
 *  This board file is made for the 7x7 mm QFN package, to convert this board
 *  file to use for other smaller device packages(5x5 mm and 4x4 mm QFN), the
 *  board will need to be modified since all the IO pins are not available for
 *  smaller packages. Note that the 2.7 x 2.7 mm WCSP package should use a
 *  separate board file also included within the SDK.
 *
 *  Refer to the datasheet for all the package options and IO descriptions:
 *  http://www.ti.com/lit/ds/symlink/cc2640r2f.pdf
 *
 *  For example, to change to the 4x4 package, remove all defines for all IOs
 *  not available (IOID_10 and higher) since the 4x4 package
 *  has only 10 DIO pins as listed in the datasheet. Remove the modules/pins
 *  not used including ADC, Display, SPI1, LED, and PIN due to limited pins.
 *  ============================================================================
 */
#ifndef __CC2640R2_LAUNCHXL_BOARD_H__
#define __CC2640R2_LAUNCHXL_BOARD_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes */
#include <ti/drivers/PIN.h>
#include <ti/devices/cc26x0r2/driverlib/ioc.h>

/* Externs */
extern const PIN_Config BoardGpioInitTable[];

/* Defines */
#define CC2640R2_LAUNCHXL

/* Mapping of pins to board signals using general board aliases
 *      <board signal alias>                  <pin mapping>
 */

/* Analog Capable DIOs */
#define CC2640R2_LAUNCHXL_DIO24_ANALOG          IOID_8



/*!
 *  @brief  Initialize the general board specific settings
 *
 *  This function initializes the general board specific settings.
 */
void CC2640R2_LAUNCHXL_initGeneral(void);

/*!
 *  @brief  Turn off the external flash on LaunchPads
 *
 */
/*!
 *  @def    CC2640R2_LAUNCHXL_ADCBufName
 *  @brief  Enum of ADCs
 */
typedef enum CC2640R2_LAUNCHXL_ADCBufName {
    CC2640R2_LAUNCHXL_ADCBUF0 = 0,
    CC2640R2_LAUNCHXL_ADCBUFCOUNT
} CC2640R2_LAUNCHXL_ADCBufName;

/*!
 *  @def    CC2640R2_LAUNCHXL_ADCBuf0SourceName
 *  @brief  Enum of ADCBuf channels
 */
typedef enum CC2640R2_LAUNCHXL_ADCBuf0ChannelName {
    CC2640R2_LAUNCHXL_ADCBUF0CHANNEL0 = 0,
    CC2640R2_LAUNCHXL_ADCBUF0CHANNELVDDS,
    CC2640R2_LAUNCHXL_ADCBUF0CHANNELDCOUPL,
    CC2640R2_LAUNCHXL_ADCBUF0CHANNELVSS,

    CC2640R2_LAUNCHXL_ADCBUF0CHANNELCOUNT
} CC2640R2_LAUNCHXL_ADCBuf0ChannelName;

/*!
 *  @def    CC2640R2_LAUNCHXL_GPTimerName
 *  @brief  Enum of GPTimer parts
 */
typedef enum CC2640R2_LAUNCHXL_GPTimerName {
    CC2640R2_LAUNCHXL_GPTIMER0A = 0,


    CC2640R2_LAUNCHXL_GPTIMERPARTSCOUNT
} CC2640R2_LAUNCHXL_GPTimerName;

/*!
 *  @def    CC2640R2_LAUNCHXL_GPTimers
 *  @brief  Enum of GPTimers
 */
typedef enum CC2640R2_LAUNCHXL_GPTimers {
    CC2640R2_LAUNCHXL_GPTIMER0 = 0,
    CC2640R2_LAUNCHXL_GPTIMERCOUNT
} CC2640R2_LAUNCHXL_GPTimers;

/*!
 *  @def    CC2640R2_LAUNCHXL_UDMAName
 *  @brief  Enum of DMA buffers
 */
typedef enum CC2640R2_LAUNCHXL_UDMAName {
    CC2640R2_LAUNCHXL_UDMA0 = 0,

    CC2640R2_LAUNCHXL_UDMACOUNT
} CC2640R2_LAUNCHXL_UDMAName;

#ifdef __cplusplus
}
#endif

#endif /* __CC2640R2_LAUNCHXL_BOARD_H__ */
