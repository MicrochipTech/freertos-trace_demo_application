/*
 * oled.h
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

#ifndef OLED_H_
#define OLED_H_

enum display_view_tag
{
	WELCOME_VIEW,
	CLOCK_TEMP_VIEW,
	BUBBLESORT_VIEW,
	QUICKSORT_VIEW,
	ISR_VIEW
};

typedef struct
{
	uint8_t vals[128];
	uint8_t start_idx;
	uint8_t  graph_res;
	uint16_t graph_min;
	uint16_t graph_max;
	uint16_t graph_range;
}graph_t;


void graph_val(graph_t *graph, uint16_t val);
void graph_draw(graph_t *graph);
void calculate_graph_range();
void oled_init(void);
void oled_clear(uint16_t columns);
void oled_write(char *str, uint8_t line);
void tsk_OLED_update(void * pvParams);

#endif /* OLED_H_ */