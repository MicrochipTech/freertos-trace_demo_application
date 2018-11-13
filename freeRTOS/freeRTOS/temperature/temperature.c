/*
 * temperature.c
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

#include "FreeRTOS.h"
#include "task.h"
#include "temperature.h"

/* Private Data */

volatile int8_t temperature = 0;

static void _init_adc(void)
{
	VREF.CTRLA = VREF_ADC0REFSEL_1V1_gc;
	ADC0.CTRLC = ADC_REFSEL_INTREF_gc | ADC_SAMPCAP_bm | ADC_PRESC_DIV64_gc;
	ADC0.CTRLD = ADC_INITDLY_DLY16_gc;
	ADC0.SAMPCTRL = 10;
	ADC0.MUXPOS = ADC_MUXPOS_TEMPSENSE_gc;
	ADC0.CTRLA |= ADC_ENABLE_bm;
}

static int16_t _get_temperature(void)
{
	ADC0.COMMAND = ADC_STCONV_bm;

	while (!(ADC0.INTFLAGS & ADC_RESRDY_bm));
/*
	adc_reading = ADC0.RES;						// raw ADC value
	adc_reading -= SIGROW.TEMPSENSE1;				// offset correction
	adc_reading *= SIGROW.TEMPSENSE0;				// gain/slope correction: result in Kelvin
	adc_reading -= Kelvin_to_Celsius;				// Convert to Celsius
	adc_reading += 0x80;							// Add 1/2 to get correct rounding on division below
	temp >>= 8;								// Divide result to get Celsius
	
*/

	uint16_t adc_reading = ADC0.RES; // ADC conversion result with 1.1 V internal reference
	uint32_t temp = (adc_reading + 57)/2;

	uint16_t temperature_in_K = temp;
	int16_t result = temperature_in_K - 273;

	return result;
}


void temperature_service(void *pvParameters)
{
	_init_adc();

	while (1) 
	{
		temperature = (int8_t)_get_temperature();
		vTaskDelay(pdMS_TO_TICKS(125));
	}
}