/*
 * oled.c
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

#include <avr/io.h>
#include <string.h>

#include "font.h"
#include "spi0.h"
#include "ssd1306.h"
#include "oled.h"

/*OLED is 128x32 pixel, 8 pixels used for text on first line. That leaves 24 pixels to be used for bar graph */ 
graph_t bubble_graph = {.graph_res = 24, .graph_min = 560, .graph_max = 690};
graph_t quick_graph = {.graph_res = 24, .graph_min = 1350, .graph_max = 1650};
graph_t temperature_graph = {.graph_res = 24, .graph_min = 10, .graph_max = 30};

/* Fill the correct graph with new data and move start index */ 
void graph_val(graph_t *graph, uint16_t val)
{
	/* Move start index */
	graph->start_idx++;
	graph->start_idx &= 128-1;
	
	/* Fetch data from struct */
	uint8_t graph_res = graph->graph_res;
	uint16_t graph_min = graph->graph_min;
	uint16_t graph_range = graph->graph_range;

	/* Check if val >=graph_min, if yes subtract graph_min from val, if no, set val to "0" */
	val = val >= graph_min? val-graph_min : 0;
	
	/* Write number to array */
	graph->vals[graph->start_idx] = val * graph_res / graph_range;
}


void graph_draw(graph_t *graph)
{
	/* set page */
	uint8_t pixel_offset = 16;
	uint8_t graph_idx = graph->start_idx;
	ssd1306_set_column_address(0);

	/* Write data from array to page 1-3 on OLED. Start position of array is defined by graph_idx */
	for (uint8_t page = 1; page < 4; page++)
	{
		ssd1306_set_page_address(page);
		
		/* Write all 128 cols */ 
		for (uint8_t x=0; x<128; x++)
		{
			/* Update start position in array */
			graph_idx = (graph_idx + 1) & (128 - 1);

			/* Calculate how many pixes on current page and col should be turned on */
			uint8_t cur_val = graph->vals[graph_idx];
			uint8_t pixels_to_light = cur_val > pixel_offset ? cur_val - pixel_offset : 0;
			if (pixels_to_light > 8) pixels_to_light = 8;
			
			uint8_t pixels = (0xFF) << (8-pixels_to_light);
			// Write pixels to screen
			ssd1306_write_data(pixels);

		}
		pixel_offset -= 8;
	}
}

void calculate_graph_range()
{
	temperature_graph.graph_range = temperature_graph.graph_max - temperature_graph.graph_min;
	bubble_graph.graph_range = bubble_graph.graph_max - bubble_graph.graph_min;
	quick_graph.graph_range = quick_graph.graph_max - quick_graph.graph_min;
}

void oled_init(void)
{
	spi0_init();

	DISPLAY_SS_PORT.DIRSET       = DISPLAY_SS_PIN;
	DISPLAY_RESET_PORT.DIRSET    = DISPLAY_RESET_PIN;
	DISPLAY_DATA_CMD_PORT.DIRSET = DISPLAY_DATA_CMD_PIN;

	ssd1306_init();
	ssd1306_set_display_start_line_address(0);

	oled_clear(4 * 128);
	ssd1306_set_page_address(0);
}

void oled_clear(uint16_t columns)
{
	for (uint16_t column_address = 0; column_address < columns; column_address++) {
		if (column_address % 128 == 0) {
			ssd1306_set_page_address(column_address / 128);
			ssd1306_set_column_address(0);
		}
		/* Clear screen */
		ssd1306_write_data(0x00);
	}
}

void oled_write(char *str, uint8_t line)
{
	ssd1306_set_page_address(line);
	ssd1306_set_column_address(0);
	ssd1306_write_text(str);
}
