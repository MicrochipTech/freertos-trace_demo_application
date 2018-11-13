/*
 * interrupt.c
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
 
#include <avr/interrupt.h>
#include <stdbool.h>

#include "FreeRTOS.h"

#include "interrupt.h"
#include "oled.h"


/* External interrupt ISR */
ISR(PORTF_PORT_vect)
{
	vTraceStoreISRBegin(SW1_Handle);
	BaseType_t xHigherPriorityTaskWoken;

	/* We have not woken a task at the start of the ISR. */
	xHigherPriorityTaskWoken = pdFALSE;

	if(rotate_view == ISR_VIEW)
	{
		rotate_view = previous_view;
		update_needed = true;
	}

	if((rotate_view == BUBBLESORT_VIEW) | (rotate_view == QUICKSORT_VIEW) && (update_needed == false))
	{
		previous_view = rotate_view;
		rotate_view = ISR_VIEW;
		update_needed = true; 
	}

	// Clear the interrupt flag
	PORTF.INTFLAGS |= 0x40;

	vTraceStoreISREnd(0);

	if( xHigherPriorityTaskWoken )
	{
		/* Actual macro used here is port specific. */
		taskYIELD_FROM_ISR ();
	}

}

void setup_SW1_interrupt()
{
		PORTF.PIN6CTRL = PORT_PULLUPEN_bm | PORT_ISC_FALLING_gc;		// Enable pullup and falling edge int on pin
		PORTF.INTFLAGS = 0xFF;											// clear all flags before enabling global interrupt
		SW1_Handle = xTraceSetISRProperties("ISR_SW1", PRIO_ISR_SW1);

}