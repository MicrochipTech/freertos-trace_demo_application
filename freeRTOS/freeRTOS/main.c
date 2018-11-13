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
/*
 * FreeRTOS Kernel V10.0.0
 * Copyright (C) 2017 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software. If you wish to use our Amazon
 * FreeRTOS name, please do so in a fair use way that does not cause confusion.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

/*
 * The example shows FreeRTOS V10.0.0 running on a ATMega4809 with Percepio trace support.
 * Various tasks will be running and the example shows that the system responds immediately even
 * when CPU is 100% loaded.
 * 
 * When using the trace feature and streaming trace data into Percepio Tracealyzer, its possible to
 * to get real-time insight into the behavior of the system to ease development, debugging, validation and optimization of the code.
 *
 * In Main. c all the tasks are created and then the scheduler is started.
 * Pressing SW0 will change between views on the OLED.
 * Pressing SW1 will trigger the external interrupt.
 *
 * Welcome view:
 * Will display information on FreeRTOS version, device and how to
 * switch between the different views and trigger the external interrupt
 *
 * Clock and temperature view:
 * Will display the time since startup and the temperature and a temperature graph.
 * Heating or cooling the Mega4809 will cause a change in temperature.
 * Holding down Button 2 it is possible to adjust the time using Button 1 (hours) and Button 3 (minutes)
 *
 * Bubblesort view:
 * In this view, the bubblesort task will be running, consuming all free CPU time, only interrupted
 * by tasks or software timers with same or higher priority or the external interrupt being triggered.
 * Same priority task that will use round robin scheduling.
 *
 * The OLED will be updated with the number of bubblesorts/sec and a bar graph.
 * Button 1,2 and 3 can be pressed to see corresponding LEDs update and witch button
 * was pressed or released will be written to the OLED.
 * By pressing the buttons, its possible to keep the device more occupied with other tasks
 * resulting in less bubblesort iterations per sec.
 *
 * Quicksort view:
 * The same as bubblesort view, but running quicksort instead.
 *
 * Interrupt view:
 * Pressing SW1 will trigger an external interrupt.
 * The CPU will execute the ISR and the rotate view will be set to ISR_VIEW
 * Bubble and quicksort tasks will be suspended and OLED updated.
 *
 */

#include <string.h>
#include <stdio.h>

/* Scheduler include files. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "timers.h"

#include "main.h"
#include "keyboard.h"
#include "LED.h"
#include "clock.h"
#include "temperature.h"
#include "benchmark.h"
#include "software_timers.h"
#include "interrupt.h"
#include "data.h"

/* Services */
#include "spi0.h"
#include "oled.h"
#include "ssd1306.h"


int main(void)
{
	/* CPU clock divided by 2, CPU running at 3.3V and 10MHz */
	_PROTECTED_WRITE(CLKCTRL.MCLKCTRLB, 1);

	/* Set up SPI, OLED, software timers, external interrupt and calculate graph ranges */
	oled_init();
	start_software_timers();
	setup_SW1_interrupt();
	calculate_graph_range();

	/* Create queues and semaphore */
	key_queue      = xQueueCreate(10, 1);
	led_queue      = xQueueCreate(10, 1);
	oled_semaphore = xSemaphoreCreateMutex();

	/* Add queues and semaphore to registry */
	vQueueAddToRegistry(key_queue, "Key_Queue");
	vQueueAddToRegistry(led_queue, "LED_Queue");
	vQueueAddToRegistry(oled_semaphore, "OLED");

	/* Run trace initialization */
	#ifdef _trace_enabled_
		vTraceEnable(TRC_INIT);
	#endif

	/* Create the tasks. */
	xTaskCreate(tsk_keyboard, "kbrd", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 2, NULL);
	xTaskCreate(tsk_LED, "LEDs", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 2, NULL);
	xTaskCreate(tsk_main, "main", configMINIMAL_STACK_SIZE + 50, NULL, tskIDLE_PRIORITY + 2, NULL);
	xTaskCreate(tsk_clk, "clk", configMINIMAL_STACK_SIZE + 50, NULL, tskIDLE_PRIORITY + 3, NULL);
	xTaskCreate(temperature_service, "temp", configMINIMAL_STACK_SIZE + 50, NULL, tskIDLE_PRIORITY + 1, NULL);
	xTaskCreate(tsk_bubble_sort, "Bubble", configMINIMAL_STACK_SIZE + 150, NULL, tskIDLE_PRIORITY + 1, &xBubble_sort_handle);
	xTaskCreate(tsk_quick_sort, "Quick", configMINIMAL_STACK_SIZE + 100, NULL, tskIDLE_PRIORITY + 1, &xQuick_sort_handle);
	xTaskCreate(tsk_OLED_update, "OLED", configMINIMAL_STACK_SIZE + 100, NULL, tskIDLE_PRIORITY + 3, NULL);

	/*Suspend Bubble sort and Quick sort tasks */
	vTaskSuspend(xBubble_sort_handle);
	vTaskSuspend(xQuick_sort_handle);

	/* Start preemptive scheduler. */
	vTaskStartScheduler();

	return 0;
}
/*-----------------------------------------------------------*/

/*	The MAIN task when there is data in the key queue.
    If SW0 is pressed, the OLED will be cleared and the view will be changed next time the OLED task is run.
    If Button 1,2 or 3 is pressed/released, the LED queue is updated with informations on witch LED to update.
    The LED task will be run when data is put in the queue.*/

void tsk_main(void *pvParams)
{
	key_msg_t key_msg;

	/* Receive data from Queue and suspend if no data ready */
	while (xQueueReceive(key_queue, &key_msg, portMAX_DELAY)) {
		/* Check if SW0 was pressed. SW0 is used for switching between views on the OLED */
		if (key_msg.key == 0 && key_msg.state == 1) {
			/*Ignore SW0 if currecnt view is ISR_VIEW */
			if (rotate_view != ISR_VIEW)
			{
				oled_clear(4 * 128);
				rotate_view++;

				if (rotate_view >= 4) {
					rotate_view = 0;
					update_needed = true;
				}
			}
		}

		/* Checks if buttons 1,2 or 3 was pressed/released, updates the LED queue according to reported key message */
		if (key_msg.key != 0 && rotate_view != WELCOME_VIEW && rotate_view != CLOCK_TEMP_VIEW) {
			xQueueSendToBack(led_queue, &key_msg, 0);

			/* Build string to be displayed on OLED */
			sprintf(str_buff, "Button %d %s", key_msg.key, key_msg.state ? "Pushed" : "Released");
			sprintf(str_buff, "%-18s", str_buff);

			/* Get access to OLED and write string */
			if (xSemaphoreTake(oled_semaphore, pdMS_TO_TICKS(100)) == pdTRUE) {
				oled_write(str_buff, 3);
				xSemaphoreGive(oled_semaphore);
			}
		}

		/*Check if Button 2 is pressed, indicating user wants to adjust time */
		if (key_msg.key == 2 && key_msg.state == 1 && rotate_view == CLOCK_TEMP_VIEW) {
			/*Stay in adjust mode as long as Button 2 is pressed */
			while (1) {
				/* Receive data from Queue */
				if (xQueueReceive(key_queue, &key_msg, portMAX_DELAY)) {
					/*If button 1 is pressed, hours is adjusted */
					if (key_msg.key == 1 && key_msg.state == 1) {
						time.hours++;
						time.hours %= 24;
					}

					/*If button 3 is pressed, minutes is adjusted */
					if (key_msg.key == 3 && key_msg.state == 1) {
						time.minutes++;
						time.minutes %= 60;
					}

					/*Check if Button 2 is pressed, break if released */
					if (key_msg.key == 2 && key_msg.state == 0) {
						break;
					}
					/* Update OLED with clock and temperature reading */
					time.seconds = 0;
					update_time_temp();
				}
			}
		}
	}
}

/*-----------------------------------------------------------*/
/* The OLED_update task is called every 250ms and is set up to have high priority to avoid other tasks from delaying the
   update.
   The code will check the rotate_view variable to know witch view is the current one. */
void tsk_OLED_update(void *pvParams)
{
	while (1) {
		/* Get access to OLED and before attempting to update */
		if (xSemaphoreTake(oled_semaphore, pdMS_TO_TICKS(100)) == pdTRUE) {
			if (rotate_view == WELCOME_VIEW && update_needed == true) {
				/* Suspend Quick_sort task */
				vTaskSuspend(xQuick_sort_handle);

				/* Build strings and write to the OLED */
				sprintf(str_buff, "Microchip ATmega4809");
				sprintf(str_buff, "%-27s", str_buff);
				oled_write(str_buff, 0);

				sprintf(str_buff, "FreeRTOS V10.0.0");
				sprintf(str_buff, "%-27s", str_buff);
				oled_write(str_buff, 1);

				sprintf(str_buff, "Use SW0 to change view");
				sprintf(str_buff, "%-27s", str_buff);
				oled_write(str_buff, 2);

				sprintf(str_buff, "Use SW1 to trig ISR");
				sprintf(str_buff, "%-27s", str_buff);
				oled_write(str_buff, 3);

				/* set update_needed to false, only static data displayed on OLED in welcome screen so no need to run
				 * more than once */
				update_needed = false;
			}

			if (rotate_view == CLOCK_TEMP_VIEW) {
				update_needed = false;
				/* Update OLED with clock and temperature reading */
				update_time_temp();

				/* Calculate temperature graph and draw it on the OLED */
				graph_val(&temperature_graph, temperature);
				graph_draw(&temperature_graph);
			}

			if (rotate_view == BUBBLESORT_VIEW) {
				update_needed = false;
				/* Resume Bubble_sort task */
					vTaskResume(xBubble_sort_handle);

				/* When DISPLAY_BUBBLE is enabled for the first time,
				   Bubble_sort task has not been run yet and bubblesort_iterations is "0" and we do not want to update
				   the OLED */
				if (bubblesort_iterations > 0) {
					/* Build string and write to the OLED */
					sprintf(str_buff, "Bubblesort/sec : %d", bubblesort_iterations * 4);
					sprintf(str_buff, "%-30s", str_buff);
					oled_write(str_buff, 0);

					/* Calculate Bubble_sort graph and draw it on the OLED */
					graph_val(&bubble_graph, bubblesort_iterations * 4);
					graph_draw(&bubble_graph);
				}
			}
			if (rotate_view == QUICKSORT_VIEW) {
				update_needed = false;
				/* Suspend Bubble_sort task and Resume Quick_sort task*/
				vTaskSuspend(xBubble_sort_handle);
				vTaskResume(xQuick_sort_handle);

				/* When DISPLAY_QUICK is enabled for the first time,
				   Quick_sort task has not been run yet and quicksort_iterations is "0" and we do not want to update the
				   OLED */
				if (quicksort_iterations > 0) {
					/* Build string and write to the OLED */
					sprintf(str_buff, "Quicksort/sec : %d", quicksort_iterations * 4);
					sprintf(str_buff, "%-30s", str_buff);
					oled_write(str_buff, 0);

					/* Calculate Quick_sort graph and draw it on the OLED */
					graph_val(&quick_graph, quicksort_iterations * 4);
					graph_draw(&quick_graph);
				}
			}

			if (rotate_view == ISR_VIEW && update_needed == true) {
				/* If SUSPEND_BY_ISR view is run, SW1 on OLED1 Xplained PRO has been pressed and created a external interrupt.
				 */

				/* Suspend Bubble_sort and Quick_sort tasks */
				vTaskSuspend(xBubble_sort_handle);
				vTaskSuspend(xQuick_sort_handle);

				/* Clear OLED */
				oled_clear(4 * 128);

				/* Build string and write to the OLED */
				sprintf(str_buff, "Tasks suspended by ISR");
				sprintf(str_buff, "%-28s", str_buff);
				oled_write(str_buff, 0);

				sprintf(str_buff, "Press SW1 to resume");
				sprintf(str_buff, "%-28s", str_buff);
				oled_write(str_buff, 2);
				
				update_needed = false;
			}
			/* Release oled_semaphore */
			xSemaphoreGive(oled_semaphore);
		}

		/* Clear variables before next run */
		bubblesort_iterations = 0;
		quicksort_iterations  = 0;

		/* Delay until the task is run again */
		vTaskDelay(pdMS_TO_TICKS(250));
	}
}
/*	The task runs bubble sorting on a array containing 30 integers
    The task will run all the time when enabled only interrupted by tasks with same or higher priority.   */
void tsk_bubble_sort(void *pvParams)
{
	int n = sizeof my_data / sizeof my_data.data[0];

	while (1) {
		//Reset array to unsorted state
		my_data = bubbledata;

		//Run bubble_sort
		bubble_sort(my_data.data, n);

		/* Updating of bubblesort_iterations is a critical section since we also write to this
		   variable in OLED_update and this has higher priority than the current task */
		portENTER_CRITICAL();
		bubblesort_iterations++;
		portEXIT_CRITICAL();
	
	}
}

/*	The task runs iterative quick sorting on a array containing 30 integers.
    The task will run all the time when enabled only interrupted by tasks with same or higher priority.   */
void tsk_quick_sort(void *pvParams)
{
	int n = sizeof my_data / sizeof my_data.data[0];

	while (1) {
		//Reset array to unsorted state
		my_data = quickdata;

		//Run quickSortIterative 
		quickSortIterative(my_data.data, 0, n - 1);

		/* Updating of quicksort_iterations is a critical section since we also write to this
		   variable in OLED_update and this has higher priority than the current task */
		portENTER_CRITICAL();
		quicksort_iterations++;
		portEXIT_CRITICAL();

	}
}
/* Hook to trap device if a task gets stack overflow */
void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName)
{
	asm volatile("cli");
	asm volatile("break");
	while (1)
		;
}
