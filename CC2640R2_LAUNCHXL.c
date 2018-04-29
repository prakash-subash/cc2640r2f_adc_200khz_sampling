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

/*
 *  ====================== CC2640R2_LAUNCHXL.c ===================================
 *  This file is responsible for setting up the board specific items for the
 *  CC2640R2_LAUNCHXL board.
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <ti/devices/cc26x0r2/driverlib/ioc.h>
#include <ti/devices/cc26x0r2/driverlib/udma.h>
#include <ti/devices/cc26x0r2/inc/hw_ints.h>
#include <ti/devices/cc26x0r2/inc/hw_memmap.h>

#include "CC2640R2_LAUNCHXL.h"

/*
 *  =============================== ADCBuf ===============================
 */
#include <ti/drivers/ADCBuf.h>
#include <ti/drivers/adcbuf/ADCBufCC26XX.h>

ADCBufCC26XX_Object adcBufCC26xxObjects[CC2640R2_LAUNCHXL_ADCBUFCOUNT];

/*
 *  This table converts a virtual adc channel into a dio and internal analogue
 *  input signal. This table is necessary for the functioning of the adcBuf
 *  driver. Comment out unused entries to save flash. Dio and internal signal
 *  pairs are hardwired. Do not remap them in the table. You may reorder entire
 *  entries. The mapping of dio and internal signals is package dependent.
 */
const ADCBufCC26XX_AdcChannelLutEntry ADCBufCC26XX_adcChannelLut[CC2640R2_LAUNCHXL_ADCBUF0CHANNELCOUNT] = {
    {CC2640R2_LAUNCHXL_DIO24_ANALOG, ADC_COMPB_IN_AUXIO6},
    {PIN_UNASSIGNED, ADC_COMPB_IN_VDDS},
    {PIN_UNASSIGNED, ADC_COMPB_IN_DCOUPL},
    {PIN_UNASSIGNED, ADC_COMPB_IN_VSS},
};

const ADCBufCC26XX_HWAttrs adcBufCC26xxHWAttrs[CC2640R2_LAUNCHXL_ADCBUFCOUNT] = {
    {
        .intPriority       = ~0,
        .swiPriority       = 0,
        .adcChannelLut     = ADCBufCC26XX_adcChannelLut,
        .gpTimerUnit       = CC2640R2_LAUNCHXL_GPTIMER0A,
        .gptDMAChannelMask = 1 << UDMA_CHAN_TIMER0_A,
    }
};

const ADCBuf_Config ADCBuf_config[CC2640R2_LAUNCHXL_ADCBUFCOUNT] = {
    {
        &ADCBufCC26XX_fxnTable,
        &adcBufCC26xxObjects[CC2640R2_LAUNCHXL_ADCBUF0],
        &adcBufCC26xxHWAttrs[CC2640R2_LAUNCHXL_ADCBUF0]
    },
};

const uint_least8_t ADCBuf_count = CC2640R2_LAUNCHXL_ADCBUFCOUNT;

/*
 *  =============================== GPTimer ===============================
 *  Remove unused entries to reduce flash usage both in Board.c and Board.h
 */
#include <ti/drivers/timer/GPTimerCC26XX.h>

GPTimerCC26XX_Object gptimerCC26XXObjects[CC2640R2_LAUNCHXL_GPTIMERCOUNT];

const GPTimerCC26XX_HWAttrs gptimerCC26xxHWAttrs[CC2640R2_LAUNCHXL_GPTIMERPARTSCOUNT] = {
    { .baseAddr = GPT0_BASE, .intNum = INT_GPT0A, .intPriority = (~0), .powerMngrId = PowerCC26XX_PERIPH_GPT0, .pinMux = GPT_PIN_0A, },

};

const GPTimerCC26XX_Config GPTimerCC26XX_config[CC2640R2_LAUNCHXL_GPTIMERPARTSCOUNT] = {
    { &gptimerCC26XXObjects[CC2640R2_LAUNCHXL_GPTIMER0], &gptimerCC26xxHWAttrs[CC2640R2_LAUNCHXL_GPTIMER0A], GPT_A },

};

/*
 *  =============================== PIN ===============================
 */
#include <ti/drivers/PIN.h>
#include <ti/drivers/pin/PINCC26XX.h>

const PIN_Config BoardGpioInitTable[] = {
    PIN_TERMINATE
};

const PINCC26XX_HWAttrs PINCC26XX_hwAttrs = {
    .intPriority = ~0,
    .swiPriority = 0
};

/*
 *  =============================== Power ===============================
 */
#include <ti/drivers/Power.h>
#include <ti/drivers/power/PowerCC26XX.h>

const PowerCC26XX_Config PowerCC26XX_config = {
    .policyInitFxn      = NULL,
    .policyFxn          = &PowerCC26XX_standbyPolicy,
    .calibrateFxn       = &PowerCC26XX_calibrate,
    .enablePolicy       = true,
    .calibrateRCOSC_LF  = true,
    .calibrateRCOSC_HF  = true,
};

/*
 *  =============================== UDMA ===============================
 */
#include <ti/drivers/dma/UDMACC26XX.h>

UDMACC26XX_Object udmaObjects[CC2640R2_LAUNCHXL_UDMACOUNT];

const UDMACC26XX_HWAttrs udmaHWAttrs[CC2640R2_LAUNCHXL_UDMACOUNT] = {
    {
        .baseAddr    = UDMA0_BASE,
        .powerMngrId = PowerCC26XX_PERIPH_UDMA,
        .intNum      = INT_DMA_ERR,
        .intPriority = ~0
    }
};

const UDMACC26XX_Config UDMACC26XX_config[CC2640R2_LAUNCHXL_UDMACOUNT] = {
    {
         .object  = &udmaObjects[CC2640R2_LAUNCHXL_UDMA0],
         .hwAttrs = &udmaHWAttrs[CC2640R2_LAUNCHXL_UDMA0]
    },
};



/*
 *  ======== CC2640R2_LAUNCHXL_initGeneral ========
 */
void CC2640R2_LAUNCHXL_initGeneral(void)
{

    if (PIN_init(BoardGpioInitTable) != PIN_SUCCESS) {
        /* Error with PIN_init */
        while (1);
    }
}
