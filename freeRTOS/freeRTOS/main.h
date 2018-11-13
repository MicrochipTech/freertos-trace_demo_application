/*
 * main.h
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

#ifndef MAIN_H_
#define MAIN_H_

#include <stdbool.h>
#include "oled.h"
#include "clock.h"

extern graph_t temperature_graph;
extern graph_t bubble_graph;
extern graph_t quick_graph;
extern time_t time;

volatile uint16_t bubblesort_iterations = 0;
volatile uint16_t quicksort_iterations = 0;
volatile uint8_t rotate_view = 0;
volatile uint8_t previous_view = 0;

volatile uint8_t update_needed = true;

static char str_buff[31];

void tsk_main(void * pvParams);
void tsk_bubble_sort(void * pvParams);
void tsk_quick_sort(void * pvParams);

TaskHandle_t xBubble_sort_handle = NULL;
TaskHandle_t xQuick_sort_handle = NULL;

QueueHandle_t key_queue;
QueueHandle_t led_queue;
SemaphoreHandle_t oled_semaphore;


#endif /* MAIN_H_ */