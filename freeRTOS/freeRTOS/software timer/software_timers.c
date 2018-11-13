/*
 * software_timers.c
 *
 (c) 2018 Microchip Technology Inc. and its subsidiaries.

 Subject to your compliance with these terms,you may use this software and
 any derivatives exclusively with Microchip products.It is your responsibility
 to comply with third party license terms applicable to your use of third party
 software (including open source software) that may accompany Microchip software.

 THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
 EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
 WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
 PARTICULAR PURPOSE.

 IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
 INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
 WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
 BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
 FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
 ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */

/* Scheduler include files. */
#include "FreeRTOS.h"
#include "timers.h"

#include "software_timers.h"

void start_software_timers()
{
	    /* Create the one-shot timer, storing the handle to the created timer in xOneShotTimer. */

	    xOneShotTimer = xTimerCreate(  "OneShot",					/* Text name for the software timer - not used by FreeRTOS. */
								    mainONE_SHOT_TIMER_PERIOD,	/* The software timer's period, in ticks. */
								    pdFALSE,					/* Setting uxAutoRealod to pdFALSE creates a one-shot software timer. */
								    0,							/* This example does not use the timer ID. */
								    prvTimerCallback );  /* The callback function to be used by the software timer being created. */

    /* Create the auto-reload timer, storing the handle to the created timer in xAutoReloadTimer. */

    xAutoReloadTimer = xTimerCreate( "AutoReload",					/* Text name for the software timer - not used by FreeRTOS. */
									  mainAUTO_RELOAD_TIMER_PERIOD, /* The software timer's period, in ticks. */
									  pdTRUE,						/* Setting uxAutoRealod to pdTRUE creates an auto-reload timer. */
									  0,							/* This example does not use the timer ID. */
									  prvTimerCallback );	/* The callback function to be used by the software timer being created. */

    /* Check the software timers were created. */
    if( ( xOneShotTimer != NULL ) && ( xAutoReloadTimer != NULL ) )
    {
	    /* Start the software timers, using a block time of 0 (no block time). 
		The scheduler has not been started yet so any block time specified here would be ignored anyway. */

	    xTimerStart( xOneShotTimer, 0 );
		xTimerStart( xAutoReloadTimer, 0 );
	}


}

/* Common Timer callback function used for both timers. 
   Oneshot timer enabled tracing and autoreload timer toggles the status LED every 300ms*/
void prvTimerCallback( TimerHandle_t xTimer )
{
	if( xTimer == xOneShotTimer )
	{
	#ifdef _trace_enabled_
		vTraceEnable(TRC_START);
	#endif

	}
	else
	{
		PORTB.DIRSET = PIN5_bm;
		PORTB.OUTTGL = PIN5_bm;
	}
}

