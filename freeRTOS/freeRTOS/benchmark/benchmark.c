/*
 * benchmark.c
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

#include "benchmark.h"

void bubble_sort(int *a, int n)
{
	int i, t, s = 1;
	while (s) {
		s = 0;
		for (i = 1; i < n; i++) {
			if (a[i] < a[i - 1]) {
				t        = a[i];
				a[i]     = a[i - 1];
				a[i - 1] = t;
				s        = 1;
			}
		}
	}
}


/* *a --> Pointer to array to be sorted, 
   l  --> Starting index, 
   h  --> Ending index */
void quickSortIterative (int *a, int l, int h)
{
    // Create an auxiliary stack
    int stack[10];
 
    // initialize top of stack
    int top = -1;
 
    // push initial values of l and h to stack
    stack[ ++top ] = l;
    stack[ ++top ] = h;
 
    // Keep popping from stack while is not empty
    while ( top >= 0 )
    {
        // Pop h and l
        h = stack[ top-- ];
        l = stack[ top-- ];
 
        // Set pivot element at its correct position
        // in sorted array
        int p = partition( a, l, h );
 
        // If there are elements on left side of pivot,
        // then push left side to stack
        if ( p-1 > l )
        {
            stack[ ++top ] = l;
            stack[ ++top ] = p - 1;
        }
 
        // If there are elements on right side of pivot,
        // then push right side to stack
        if ( p+1 < h )
        {
            stack[ ++top ] = p + 1;
            stack[ ++top ] = h;
        }
    }
}

int partition(int Quick_Array[], int l, int r)
{
	int pivot, i, j, t;
	pivot = Quick_Array[l];
	i     = l;
	j     = r + 1;

	while (1) {
		do
			++i;
		while (Quick_Array[i] <= pivot && i <= r);
		do
			--j;
		while (Quick_Array[j] > pivot);
		if (i >= j)
			break;
		t              = Quick_Array[i];
		Quick_Array[i] = Quick_Array[j];
		Quick_Array[j] = t;
	}
	t              = Quick_Array[l];
	Quick_Array[l] = Quick_Array[j];
	Quick_Array[j] = t;
	return j;
}
