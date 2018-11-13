/*
 * oled_pins.h
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

#ifndef DISPLAY_PINS_H_
#define DISPLAY_PINS_H_

#define DISPLAY_SS_PORT       PORTF
#define DISPLAY_SS_PIN        PIN2_bm
#define DISPLAY_RESET_PORT    PORTE
#define DISPLAY_RESET_PIN     PIN3_bm
#define DISPLAY_DATA_CMD_PORT PORTD
#define DISPLAY_DATA_CMD_PIN  PIN0_bm

static void display_ss_set_level(const bool level)
{
	if (level == true)
	{
		DISPLAY_SS_PORT.OUTSET = DISPLAY_SS_PIN;
	}
	else
	{
		DISPLAY_SS_PORT.OUTCLR = DISPLAY_SS_PIN;
	}
}

static void display_reset_set_level(const bool level)
{
	if (level == true)
	{
		DISPLAY_RESET_PORT.OUTSET = DISPLAY_RESET_PIN;
	}
	else
	{
		DISPLAY_RESET_PORT.OUTCLR = DISPLAY_RESET_PIN;
	}
}

static void display_data_cmd_set_level(const bool level)
{
	if (level == true)
	{
		DISPLAY_DATA_CMD_PORT.OUTSET = DISPLAY_DATA_CMD_PIN;
	}
	else
	{
		DISPLAY_DATA_CMD_PORT.OUTCLR = DISPLAY_DATA_CMD_PIN;
	}
}

#endif /* OLED_PINS_H_ */