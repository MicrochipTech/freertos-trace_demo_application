/*
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

#include "trcRecorder.h"
#include <avr/interrupt.h>

#if (TRC_USE_TRACEALYZER_RECORDER == 1)
#if(TRC_CFG_RECORDER_MODE == TRC_RECORDER_MODE_STREAMING)

#include "stdint.h"

/* Include files as needed, in this case it is files from STM32Cube FW_F7 V1.4.1 */

#define BUFSIZE 64

typedef struct{
	uint32_t idx;
	uint8_t data[BUFSIZE];
}recBuf;

/* Define size for the receive and transmit buffer over CDC */
#define APP_RX_DATA_SIZE  8
#define APP_TX_DATA_SIZE  64

/* Received Data over USB are stored in this buffer       */
volatile uint8_t UserRxBuffer[APP_RX_DATA_SIZE];
volatile uint8_t rx_wr_ptr = 0;
uint8_t rx_rd_ptr = 0;

/* Send Data over USB CDC are stored in this buffer       */
uint8_t UserTxBuffer[APP_TX_DATA_SIZE];


 void usart_init(void)
{
	USART1.BAUD = 0x40;   //625000 @ 10MHz
	USART1.CTRLB = USART_TXEN_bm | USART_RXEN_bm | USART_RXMODE_CLK2X_gc;//enable doublespeed mode
	USART1.DBGCTRL = USART_DBGRUN_bm;
	PORTC.DIRSET = PIN0_bm;
	USART1.CTRLA = USART_RXCIF_bm;
}

/* The READ function, used in trcStreamingPort.h */
int32_t usart_rx_pkt(void *data, uint32_t size, int32_t* NumBytes)
{
	uint8_t *rx_buff = (uint8_t *)data;
	*NumBytes=size;
	for (;size>0;size--)
	{
		while(rx_wr_ptr == rx_rd_ptr);
		*rx_buff = UserRxBuffer[rx_rd_ptr];
		rx_buff++;
		rx_rd_ptr++;
		rx_rd_ptr %= 8;
	}
	return 0;
}

/* The WRITE function, used in trcStreamingPort.h */
int32_t usart_tx_pkt(void* data, uint32_t size, int32_t * noOfBytesSent )
{
	uint8_t * data_ptr = (uint8_t *)data;
	for (;size > 0; size--)
	{
		while (!(USART1.STATUS & USART_DREIF_bm));
		USART1.TXDATAL = *data_ptr;
		data_ptr++;
	}
	return 0;
}

ISR(USART1_RXC_vect)
{
	UserRxBuffer[rx_wr_ptr++] = USART1.RXDATAL;
	rx_wr_ptr %= 8;
}

#endif	/*(TRC_CFG_RECORDER_MODE == TRC_RECORDER_MODE_STREAMING)*/
#endif  /*(TRC_USE_TRACEALYZER_RECORDER == 1)*/

