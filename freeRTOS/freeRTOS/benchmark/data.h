/*
 * data.h
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



#ifndef INCFILE1_H_
#define INCFILE1_H_

typedef struct {int data[30];} dataset_t;
dataset_t my_data;

#define bubbledata (dataset_t){{23, -22, 18, 19, -255, 0, 291, -83, 1582, 18, 555, 39, 2456, 90, -224, -2, 66, -1345, 3, 3, 889, 109, -3547, 0, 33, 23, -44, -1, -54, 37}}
#define quickdata (dataset_t){{23, -22, 18, 19, -255, 0, 291, -83, 1582, 18, 555, 39, 2456, 90, -224, -2, 66, -1345, 3, 3, 889, 109, -3547, 0, 33, 23, -44, -1, -54, 37}}

#endif /* INCFILE1_H_ */