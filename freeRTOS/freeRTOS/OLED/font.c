/**
 * \file
 *
 * \brief SSD1306 fonts.
 *
 * Copyright (c) 2014-2015 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#include <avr/io.h>

#include "font.h"
/*===================================*/
/*========= Characters data =========*/
/*===================================*/

/** 0x20 - 32 - ' '  **/
const __flash uint8_t Font08px_space[3] = {2,
										bits2bytes(0, 0, 0, 0, 0, 0, 0, 0),
										bits2bytes(0, 0, 0, 0, 0, 0, 0, 0)};

/** 0x21 - 33 - '!'  **/
const __flash uint8_t Font08px_exclemation[2] = {1,
                                        bits2bytes(1, 0, 1, 1, 1, 1, 1, 0)};

/** 0x22 - 34 - '"'  **/
const __flash uint8_t Font08px_quotation[4] = {3,
                                        bits2bytes(0, 0, 0, 0, 0, 0, 1, 1),
										bits2bytes(0, 0, 0, 0, 0, 0, 0, 0),
										bits2bytes(0, 0, 0, 0, 0, 0, 1, 1)};

/** 0x23 - 35 - '#'  **/
const __flash uint8_t Font08px_hash[6] = {5,
										bits2bytes(0, 1, 0, 1, 0, 0, 0, 0),
                                        bits2bytes(1, 1, 1, 1, 1, 0, 0, 0),
                                        bits2bytes(0, 1, 0, 1, 0, 0, 0, 0),
                                        bits2bytes(1, 1, 1, 1, 1, 0, 0, 0),
                                        bits2bytes(0, 1, 0, 1, 0, 0, 0, 0)};

/** 0x24 - 36 - '$'  **/
const __flash uint8_t Font08px_dollar[6] = {5,
                                        bits2bytes(0, 1, 0, 0, 1, 1, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 1, 0, 1, 0),
                                        bits2bytes(1, 1, 1, 1, 1, 1, 1, 1),
                                        bits2bytes(1, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(0, 1, 1, 0, 0, 1, 0, 0)};

/** 0x25 - 37 - '%'  **/
const __flash uint8_t Font08px_percentage[8] = {7,
                                        bits2bytes(1, 0, 0, 0, 0, 1, 0, 0),
                                        bits2bytes(0, 1, 0, 0, 1, 0, 1, 0),
                                        bits2bytes(0, 0, 1, 0, 0, 1, 0, 0),
                                        bits2bytes(0, 0, 0, 1, 0, 0, 0, 0),
                                        bits2bytes(0, 1, 0, 0, 1, 0, 0, 0),
                                        bits2bytes(1, 0, 1, 0, 0, 1, 0, 0),
                                        bits2bytes(0, 1, 0, 0, 0, 0, 1, 0)};

/** 0x26 - 38 - '&'  **/
const __flash uint8_t Font08px_and[7] = {6,
                                        bits2bytes(0, 1, 1, 1, 0, 1, 1, 0),
                                        bits2bytes(1, 0, 0, 0, 1, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 1, 0, 1, 1, 0),
                                        bits2bytes(1, 0, 1, 0, 0, 0, 0, 0),
                                        bits2bytes(0, 1, 0, 0, 0, 0, 0, 0),
                                        bits2bytes(1, 0, 1, 0, 0, 0, 0, 0)};

/** 0x27 - 39 - '''  **/
const __flash uint8_t Font08px_apostrophe[2] = {1,
										bits2bytes(0, 0, 0, 0, 0, 0, 1, 1)};

/** 0x28 - 40 - '('  **/
const __flash uint8_t Font08px_parentheses[4] = {3,
										bits2bytes(0, 1, 1, 1, 1, 1, 1, 0),
										bits2bytes(1, 0, 0, 0, 0, 0, 0, 1),
										bits2bytes(0, 0, 0, 0, 0, 0, 0, 0)};
/** 0x29 - 41 - ')'  **/
const __flash uint8_t Font08px_closing_parentheses[4] = {3,
										bits2bytes(0, 0, 0, 0, 0, 0, 0, 0),
										bits2bytes(1, 0, 0, 0, 0, 0, 0, 1),
										bits2bytes(0, 1, 1, 1, 1, 1, 1, 0)};

/** 0x2A - 42 - '*'  **/
const __flash uint8_t Font08px_star[6] = {5,
                                        bits2bytes(0, 0, 1, 0, 1, 0, 1, 0),
										bits2bytes(0, 0, 0, 1, 1, 1, 0, 0),
										bits2bytes(0, 0, 1, 1, 1, 1, 1, 0),
										bits2bytes(0, 0, 0, 1, 1, 1, 0, 0),
										bits2bytes(0, 0, 1, 0, 1, 0, 1, 0)};

/** 0x2B - 43 - '+'  **/
const __flash uint8_t Font08px_plus[6] = {5,
                                        bits2bytes(0, 0, 0, 1, 0, 0, 0, 0),
                                        bits2bytes(0, 0, 0, 1, 0, 0, 0, 0),
                                        bits2bytes(0, 1, 1, 1, 1, 1, 0, 0),
                                        bits2bytes(0, 0, 0, 1, 0, 0, 0, 0),
                                        bits2bytes(0, 0, 0, 1, 0, 0, 0, 0)};

/** 0x2C - 44 - ','  **/
const __flash uint8_t Font08px_comma[4] = {3,
                                        bits2bytes(1, 0, 0, 0, 0, 0, 0, 0),
                                        bits2bytes(0, 1, 0, 0, 0, 0, 0, 0),
                                        bits2bytes(0, 0, 0, 0, 0, 0, 0, 0)};

/** 0x2D - 45 - '-'  **/
const __flash uint8_t Font08px_minus[4] = {3,
										bits2bytes(0, 0, 1, 0, 0, 0, 0, 0),
										bits2bytes(0, 0, 1, 0, 0, 0, 0, 0),
										bits2bytes(0, 0, 1, 0, 0, 0, 0, 0)};
/** 0x2E - 46 - '.'  **/
const __flash uint8_t Font08px_period[4] = {3,
										bits2bytes(0, 0, 0, 0, 0, 0, 0, 0),
										bits2bytes(1, 0, 0, 0, 0, 0, 0, 0),
										bits2bytes(0, 0, 0, 0, 0, 0, 0, 0)};

/** 0x2F - 47 - '/'  **/
const __flash uint8_t Font08px_slash[5] = {4,
                                        bits2bytes(1, 1, 0, 0, 0, 0, 0, 0),
                                        bits2bytes(0, 0, 1, 1, 0, 0, 0, 0),
                                        bits2bytes(0, 0, 0, 0, 1, 1, 0, 0),
                                        bits2bytes(0, 0, 0, 0, 0, 0, 1, 0)};

/**  0x30 - 48  - '0'  **/
const __flash uint8_t Font08px_N0[6] = {5,
                                        bits2bytes(0, 1, 1, 1, 1, 1, 0, 0),
                                        bits2bytes(1, 0, 1, 0, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 0, 1, 0, 1, 0),
                                        bits2bytes(0, 1, 1, 1, 1, 1, 0, 0)};

/**  0x31 - 49  - '1'  **/
const __flash uint8_t Font08px_N1[6] = {5,
                                        bits2bytes(0, 0, 0, 0, 0, 0, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 1, 0, 0),
                                        bits2bytes(1, 1, 1, 1, 1, 1, 1, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 0, 0),
                                        bits2bytes(0, 0, 0, 0, 0, 0, 0, 0)};

/**  0x32 - 50  - '2'  **/
const __flash uint8_t Font08px_N2[6] = {5,
                                        bits2bytes(1, 0, 0, 0, 0, 1, 0, 0),
                                        bits2bytes(1, 1, 0, 0, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 1, 0, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 0, 1, 1, 0, 0)};

/**  0x33 - 51  - '3'  **/
const __flash uint8_t Font08px_N3[6] = {5,
                                        bits2bytes(0, 1, 0, 0, 0, 1, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(0, 1, 1, 0, 1, 1, 0, 0)};

/**  0x34 - 52  - '4'  **/
const __flash uint8_t Font08px_N4[6] = {5,
                                        bits2bytes(0, 0, 1, 1, 0, 0, 0, 0),
                                        bits2bytes(0, 0, 1, 0, 1, 0, 0, 0),
                                        bits2bytes(0, 0, 1, 0, 0, 1, 0, 0),
                                        bits2bytes(1, 1, 1, 1, 1, 1, 1, 0),
                                        bits2bytes(0, 0, 1, 0, 0, 0, 0, 0)};

/**  0x35 - 53  - '5'  **/
const __flash uint8_t Font08px_N5[6] = {5,
                                        bits2bytes(0, 1, 0, 1, 1, 1, 1, 0),
                                        bits2bytes(1, 0, 0, 0, 1, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 0, 1, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 0, 1, 0, 1, 0),
                                        bits2bytes(0, 1, 1, 1, 0, 0, 1, 0)};

/**  0x36 - 54  - '6'  **/
const __flash uint8_t Font08px_N6[6] = {5,
                                        bits2bytes(0, 1, 1, 1, 1, 1, 0, 0),
                                        bits2bytes(1, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(0, 1, 1, 0, 0, 1, 0, 0)};

/**  0x37 - 55  - '7'  **/
const __flash uint8_t Font08px_N7[6] = {5,
                                        bits2bytes(0, 0, 0, 0, 0, 0, 1, 0),
                                        bits2bytes(0, 0, 0, 0, 0, 0, 1, 0),
                                        bits2bytes(1, 1, 1, 1, 0, 0, 1, 0),
                                        bits2bytes(0, 0, 0, 0, 1, 0, 1, 0),
                                        bits2bytes(0, 0, 0, 0, 0, 1, 1, 0)};

/**  0x38 - 56  - '8'  **/
const __flash uint8_t Font08px_N8[6] = {5,
                                        bits2bytes(0, 1, 1, 0, 1, 1, 0, 0),
                                        bits2bytes(1, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(0, 1, 1, 0, 1, 1, 0, 0)};

/**  0x39 - 57  - '9'  **/
const __flash uint8_t Font08px_N9[6] = {5,
                                        bits2bytes(0, 1, 0, 0, 1, 1, 0, 0),
                                        bits2bytes(1, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(0, 1, 1, 1, 1, 1, 0, 0)};

/** 0x3A - 58 - ':'  **/
const __flash uint8_t Font08px_colon[3] = {2,
                                        bits2bytes(0, 1, 0, 0, 0, 1, 0, 0),
                                        bits2bytes(0, 0, 0, 0, 0, 0, 0, 0)};

/** 0x3B - 59 - ';'  **/
const __flash uint8_t Font08px_semicolon[4] = {3,
										bits2bytes(1, 0, 0, 0, 0, 0, 0, 0),
                                        bits2bytes(0, 1, 0, 0, 0, 1, 0, 0),
                                        bits2bytes(0, 0, 0, 0, 0, 0, 0, 0)};

/** 0x3C - 60 - '<'  **/
const __flash uint8_t Font08px_les_than[4] = {3,
                                        bits2bytes(0, 0, 0, 1, 0, 0, 0, 0),
                                        bits2bytes(0, 0, 1, 0, 1, 0, 0, 0),
                                        bits2bytes(0, 1, 0, 0, 0, 1, 0, 0)};

/** 0x3D - 61 - '='  **/
const __flash uint8_t Font08px_equals[4] = {3,
                                        bits2bytes(0, 0, 1, 0, 1, 0, 0, 0),
                                        bits2bytes(0, 0, 1, 0, 1, 0, 0, 0),
                                        bits2bytes(0, 0, 1, 0, 1, 0, 0, 0)};

/** 0x3E - 62 - '>'  **/
const __flash uint8_t Font08px_more_than[4] = {3,
                                        bits2bytes(0, 1, 0, 0, 0, 1, 0, 0),
                                        bits2bytes(0, 0, 1, 0, 1, 0, 0, 0),
                                        bits2bytes(0, 0, 0, 1, 0, 0, 0, 0)};

/** 0x3F - 63 - '?'  **/
const __flash uint8_t Font08px_questionmark[5] = {4,
                                        bits2bytes(0, 0, 0, 0, 0, 1, 0, 0),
                                        bits2bytes(1, 0, 1, 1, 0, 0, 1, 0),
                                        bits2bytes(0, 0, 0, 0, 1, 0, 1, 0),
                                        bits2bytes(0, 0, 0, 0, 0, 1, 0, 0)};

/** 0x40 - 64 - '@'  **/
const __flash uint8_t Font08px_curlya[8] = {7,
                                        bits2bytes(0, 0, 1, 1, 1, 0, 0, 0),
                                        bits2bytes(0, 1, 0, 0, 0, 1, 0, 0),
                                        bits2bytes(1, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 1, 0, 1, 0, 1, 0),
                                        bits2bytes(1, 0, 1, 1, 1, 0, 1, 0),
                                        bits2bytes(1, 0, 1, 0, 0, 0, 1, 0),
                                        bits2bytes(0, 0, 0, 1, 1, 1, 0, 0)};

/** 0x41 - 65 - 'A'  **/
const __flash uint8_t Font08px_UA[7] = {6,
                                        bits2bytes(1, 1, 1, 1, 1, 1, 0, 0),
                                        bits2bytes(0, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(0, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(0, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(0, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(1, 1, 1, 1, 1, 1, 0, 0)};

/** 0x42 - 66 - 'B'  **/
const __flash uint8_t Font08px_UB[7] = {6,
                                        bits2bytes(1, 1, 1, 1, 1, 1, 1, 0),
                                        bits2bytes(1, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(0, 1, 1, 0, 1, 1, 0, 0)};

/** 0x43 - 67 - 'C'  **/
const __flash uint8_t Font08px_UC[7] = {6,
                                        bits2bytes(0, 1, 1, 1, 1, 1, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 1, 0)};

/** 0x44 - 68 - 'D'  **/
const __flash uint8_t Font08px_UD[7] = {6,
                                        bits2bytes(1, 1, 1, 1, 1, 1, 1, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 1, 0),
                                        bits2bytes(0, 1, 0, 0, 0, 1, 0, 0),
                                        bits2bytes(0, 0, 1, 1, 1, 0, 0, 0)};

/** 0x45 - 69 - 'E'  **/
const __flash uint8_t Font08px_UE[7] = {6,
                                        bits2bytes(1, 1, 1, 1, 1, 1, 1, 0),
                                        bits2bytes(1, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 1, 0)};

/** 0x46 - 70 - 'F'  **/
const __flash uint8_t Font08px_UF[7] = {6,
                                        bits2bytes(1, 1, 1, 1, 1, 1, 1, 0),
                                        bits2bytes(0, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(0, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(0, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(0, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(0, 0, 0, 0, 0, 0, 1, 0)};

/** 0x47 - 71 - 'G'  **/
const __flash uint8_t Font08px_UG[7] = {6,
                                        bits2bytes(0, 1, 1, 1, 1, 1, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(1, 1, 1, 1, 0, 1, 0, 0)};

/** 0x48 - 72 - 'H'  **/
const __flash uint8_t Font08px_UH[7] = {6,
                                        bits2bytes(1, 1, 1, 1, 1, 1, 1, 0),
                                        bits2bytes(0, 0, 0, 1, 0, 0, 0, 0),
                                        bits2bytes(0, 0, 0, 1, 0, 0, 0, 0),
                                        bits2bytes(0, 0, 0, 1, 0, 0, 0, 0),
                                        bits2bytes(0, 0, 0, 1, 0, 0, 0, 0),
                                        bits2bytes(1, 1, 1, 1, 1, 1, 1, 0)};

/** 0x49 - 73 - 'I'  **/
const __flash uint8_t Font08px_UI[4] = {3,
                                        bits2bytes(1, 0, 0, 0, 0, 0, 1, 0),
                                        bits2bytes(1, 1, 1, 1, 1, 1, 1, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 1, 0)};

/** 0x4A - 74 - 'J'  **/
const __flash uint8_t Font08px_UJ[5] = {4,
                                        bits2bytes(0, 1, 0, 0, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 1, 0),
                                        bits2bytes(0, 1, 1, 1, 1, 1, 1, 0)};

/** 0x4B - 75 - 'K'  **/
const __flash uint8_t Font08px_UK[7] = {6,
                                        bits2bytes(1, 1, 1, 1, 1, 1, 1, 0),
                                        bits2bytes(0, 0, 0, 1, 0, 0, 0, 0),
                                        bits2bytes(0, 0, 0, 1, 0, 0, 0, 0),
                                        bits2bytes(0, 0, 1, 0, 1, 0, 0, 0),
                                        bits2bytes(0, 1, 0, 0, 0, 1, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 1, 0)};

/** 0x4C - 76 - 'L'  **/
const __flash uint8_t Font08px_UL[7] = {6,
                                        bits2bytes(1, 1, 1, 1, 1, 1, 1, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 0, 0)};

/** 0x4D - 77 - 'M'  **/
const __flash uint8_t Font08px_UM[8] = {7,
                                        bits2bytes(1, 1, 1, 1, 1, 1, 1, 0),
                                        bits2bytes(0, 0, 0, 0, 0, 1, 0, 0),
                                        bits2bytes(0, 0, 0, 0, 1, 0, 0, 0),
                                        bits2bytes(1, 1, 1, 1, 0, 0, 0, 0),
                                        bits2bytes(0, 0, 0, 0, 1, 0, 0, 0),
                                        bits2bytes(0, 0, 0, 0, 0, 1, 0, 0),
                                        bits2bytes(1, 1, 1, 1, 1, 1, 1, 0)};

/** 0x4E - 78 - 'N'  **/
const __flash uint8_t Font08px_UN[8] = {7,
                                        bits2bytes(1, 1, 1, 1, 1, 1, 1, 0),
                                        bits2bytes(0, 0, 0, 0, 0, 1, 0, 0),
                                        bits2bytes(0, 0, 0, 0, 1, 0, 0, 0),
                                        bits2bytes(0, 0, 0, 1, 0, 0, 0, 0),
                                        bits2bytes(0, 0, 1, 0, 0, 0, 0, 0),
                                        bits2bytes(0, 1, 0, 0, 0, 0, 0, 0),
                                        bits2bytes(1, 1, 1, 1, 1, 1, 1, 0)};

/** 0x4F - 79 - 'O'  **/
const __flash uint8_t Font08px_UO[7] = {6,
                                        bits2bytes(0, 1, 1, 1, 1, 1, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 1, 0),
                                        bits2bytes(0, 1, 1, 1, 1, 1, 0, 0)};

/** 0x50 - 80 - 'P'  **/
const __flash uint8_t Font08px_UP[7] = {6,
                                        bits2bytes(1, 1, 1, 1, 1, 1, 1, 0),
                                        bits2bytes(0, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(0, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(0, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(0, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(0, 0, 0, 0, 1, 1, 0, 0)};

/** 0x51 - 81 - 'Q'  **/
const __flash uint8_t Font08px_UQ[7] = {6,
                                        bits2bytes(0, 1, 1, 1, 1, 1, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 1, 0, 0, 0, 1, 0),
                                        bits2bytes(0, 1, 0, 0, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 1, 1, 1, 1, 0, 0)};

/** 0x52 - 82 - 'R'  **/
const __flash uint8_t Font08px_UR[7] = {6,
                                        bits2bytes(1, 1, 1, 1, 1, 1, 1, 0),
                                        bits2bytes(0, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(0, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(0, 0, 1, 1, 0, 0, 1, 0),
                                        bits2bytes(0, 1, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 0, 1, 1, 0, 0)};

/** 0x53 - 83 - 'S'  **/
const __flash uint8_t Font08px_US[7] = {6,
                                        bits2bytes(0, 1, 0, 0, 1, 1, 0, 0),
                                        bits2bytes(1, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(0, 1, 1, 0, 0, 1, 0, 0)};

/** 0x54 - 84 - 'T'  **/
const __flash uint8_t Font08px_UT[6] = {5,
                                        bits2bytes(0, 0, 0, 0, 0, 0, 1, 0),
                                        bits2bytes(0, 0, 0, 0, 0, 0, 1, 0),
                                        bits2bytes(1, 1, 1, 1, 1, 1, 1, 0),
                                        bits2bytes(0, 0, 0, 0, 0, 0, 1, 0),
                                        bits2bytes(0, 0, 0, 0, 0, 0, 1, 0)};

/** 0x55 - 85 - 'U'  **/
const __flash uint8_t Font08px_UU[7] = {6,
                                        bits2bytes(0, 1, 1, 1, 1, 1, 1, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 0, 0),
                                        bits2bytes(0, 1, 1, 1, 1, 1, 1, 0)};

/** 0x56 - 86 - 'V'  **/
const __flash uint8_t Font08px_UV[8] = {7,
                                        bits2bytes(0, 0, 0, 0, 0, 1, 1, 0),
                                        bits2bytes(0, 0, 0, 1, 1, 0, 0, 0),
                                        bits2bytes(0, 1, 1, 0, 0, 0, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 0, 0),
                                        bits2bytes(0, 1, 1, 0, 0, 0, 0, 0),
                                        bits2bytes(0, 0, 0, 1, 1, 0, 0, 0),
                                        bits2bytes(0, 0, 0, 0, 0, 1, 1, 0)};

/** 0x57 - 87 - 'W'  **/
const __flash uint8_t Font08px_UW[10] = {9,
                                        bits2bytes(0, 0, 0, 0, 1, 1, 1, 0),
                                        bits2bytes(0, 1, 1, 1, 0, 0, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 0, 0),
                                        bits2bytes(0, 1, 1, 0, 0, 0, 0, 0),
                                        bits2bytes(0, 0, 0, 1, 1, 1, 0, 0),
                                        bits2bytes(0, 1, 1, 0, 0, 0, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 0, 0),
                                        bits2bytes(0, 1, 1, 1, 0, 0, 0, 0),
                                        bits2bytes(0, 0, 0, 0, 1, 1, 1, 0)};

/** 0x58 - 88 - 'X'  **/
const __flash uint8_t Font08px_UX[8] = {7,
                                        bits2bytes(1, 0, 0, 0, 0, 0, 1, 0),
                                        bits2bytes(0, 1, 0, 0, 0, 1, 0, 0),
                                        bits2bytes(0, 0, 1, 0, 1, 0, 0, 0),
                                        bits2bytes(0, 0, 0, 1, 0, 0, 0, 0),
                                        bits2bytes(0, 0, 1, 0, 1, 0, 0, 0),
                                        bits2bytes(0, 1, 0, 0, 0, 1, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 1, 0)};

/** 0x59 - 89 - 'Y'  **/
const __flash uint8_t Font08px_UY[8] = {7,
                                        bits2bytes(0, 0, 0, 0, 0, 0, 1, 0),
                                        bits2bytes(0, 0, 0, 0, 0, 1, 0, 0),
                                        bits2bytes(0, 0, 0, 0, 1, 0, 0, 0),
                                        bits2bytes(1, 1, 1, 1, 0, 0, 0, 0),
                                        bits2bytes(0, 0, 0, 0, 1, 0, 0, 0),
                                        bits2bytes(0, 0, 0, 0, 0, 1, 0, 0),
                                        bits2bytes(0, 0, 0, 0, 0, 0, 1, 0)};

/** 0x5A - 90 - 'Z'  **/
const __flash uint8_t Font08px_UZ[7] = {6,
                                        bits2bytes(1, 1, 0, 0, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 1, 0, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 1, 0, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 0, 1, 0, 1, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 1, 1, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 1, 0)};

/** 0x5B - 91 - '['  **/
const __flash uint8_t Font08px_left_square_bracket[3] = {2,
                                        bits2bytes(1, 1, 1, 1, 1, 1, 1, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 1, 0)};

/** 0x5C - 92 - '\'  **/
const __flash uint8_t Font08px_backslash[5] = {4,
                                        bits2bytes(0, 0, 0, 0, 0, 1, 1, 0),
                                        bits2bytes(0, 0, 0, 1, 1, 0, 0, 0),
                                        bits2bytes(0, 1, 1, 0, 0, 0, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 0, 0)};


/** 0x5D - 93 - ']'  **/
const __flash uint8_t Font08px_right_square_bracket[3] = {2,
                                        bits2bytes(1, 0, 0, 0, 0, 0, 1, 0),
										bits2bytes(1, 1, 1, 1, 1, 1, 1, 0)};

/** 0x5E - 94 - '^'  **/
const __flash uint8_t Font08px_caret[4] = {3,
                                        bits2bytes(0, 0, 0, 0, 0, 1, 0, 0),
                                        bits2bytes(0, 0, 0, 0, 0, 0, 1, 0),
                                        bits2bytes(0, 0, 0, 0, 0, 1, 0, 0)};

/** 0x5F - 95 - '_'  **/
const __flash uint8_t Font08px_underscore[6] = {5,
                                        bits2bytes(1, 0, 0, 0, 0, 0, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 0, 0)};

/** 0x60 - 96 - '`'  **/
const __flash uint8_t Font08px_grave_acent[3] = {2,
                                        bits2bytes(0, 0, 0, 0, 0, 1, 0, 0),
                                        bits2bytes(0, 0, 0, 0, 0, 0, 1, 0)};


/**  0x61 - 97  - 'a'  **/
const __flash uint8_t Font08px_la[5] = {4,
                                        bits2bytes(0, 1, 1, 1, 0, 0, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 1, 0, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 1, 0, 0, 0),
                                        bits2bytes(1, 1, 1, 1, 1, 0, 0, 0)};

/**  0x62 - 98  - 'b'  **/
const __flash uint8_t Font08px_lb[5] = {4,
                                        bits2bytes(1, 1, 1, 1, 1, 1, 1, 0),
                                        bits2bytes(1, 0, 0, 0, 1, 0, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 1, 0, 0, 0),
                                        bits2bytes(0, 1, 1, 1, 0, 0, 0, 0)};

/**  0x63 - 99  - 'c'  **/
const __flash uint8_t Font08px_lc[5] = {4,
                                        bits2bytes(0, 1, 1, 1, 0, 0, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 1, 0, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 1, 0, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 1, 0, 0, 0)};

/**  0x64 - 100 - 'd'  **/
const __flash uint8_t Font08px_ld[5] = {4,
                                        bits2bytes(0, 1, 1, 1, 0, 0, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 1, 0, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 1, 0, 0, 0),
                                        bits2bytes(1, 1, 1, 1, 1, 1, 1, 0)};

/**  0x65 - 101 - 'e'  **/
const __flash uint8_t Font08px_le[5] = {4,
                                        bits2bytes(0, 1, 1, 1, 0, 0, 0, 0),
                                        bits2bytes(1, 0, 1, 0, 1, 0, 0, 0),
                                        bits2bytes(1, 0, 1, 0, 1, 0, 0, 0),
                                        bits2bytes(0, 0, 1, 1, 0, 0, 0, 0)};

/**  0x66 - 102 - 'f'  **/
const __flash uint8_t Font08px_lf[4] = {3,
										bits2bytes(1, 1, 1, 1, 1, 1, 0, 0),
										bits2bytes(0, 0, 0, 1, 0, 0, 1, 0),
										bits2bytes(0, 0, 0, 0, 0, 0, 1, 0)};

/**  0x67 - 103 - 'g'  **/
const __flash uint8_t Font08px_lg[5] = {4,
                                        bits2bytes(0, 0, 0, 1, 0, 0, 0, 0),
                                        bits2bytes(1, 0, 1, 0, 1, 0, 0, 0),
                                        bits2bytes(1, 0, 1, 0, 1, 0, 0, 0),
                                        bits2bytes(0, 1, 1, 1, 1, 0, 0, 0)};

/**  0x68 - 104 - 'h'  **/
const __flash uint8_t Font08px_lh[5] = {4,
                                        bits2bytes(1, 1, 1, 1, 1, 1, 1, 0),
                                        bits2bytes(0, 0, 0, 1, 0, 0, 0, 0),
                                        bits2bytes(0, 0, 0, 0, 1, 0, 0, 0),
                                        bits2bytes(1, 1, 1, 1, 0, 0, 0, 0)};

/**  0x69 - 105 - 'i'  **/
const __flash uint8_t Font08px_li[2] = {1,
										bits2bytes(1, 1, 1, 1, 1, 0, 1, 0)};

/**  0x6A - 106 - 'j'  **/
const __flash uint8_t Font08px_lj[3] = {2,
										bits2bytes(1, 0, 0, 0, 0, 0, 0, 0),
										bits2bytes(0, 1, 1, 1, 1, 0, 1, 0)};

/**  0x6B - 107 - 'k'  **/
const __flash uint8_t Font08px_lk[5] = {4,
                                        bits2bytes(1, 1, 1, 1, 1, 1, 1, 0),
                                        bits2bytes(0, 0, 1, 0, 0, 0, 0, 0),
                                        bits2bytes(0, 1, 0, 1, 0, 0, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 1, 0, 0, 0)};

/**  0x6C - 108 - 'l'  **/
const __flash uint8_t Font08px_ll[2] = {1,
										bits2bytes(1, 1, 1, 1, 1, 1, 1, 0)};

/**  0x6D - 109 - 'm'  **/
const __flash uint8_t Font08px_lm[6] = {5,
                                        bits2bytes(1, 1, 1, 1, 1, 0, 0, 0),
                                        bits2bytes(0, 0, 0, 0, 1, 0, 0, 0),
                                        bits2bytes(1, 1, 1, 1, 0, 0, 0, 0),
                                        bits2bytes(0, 0, 0, 0, 1, 0, 0, 0),
                                        bits2bytes(1, 1, 1, 1, 0, 0, 0, 0)};

/**  0x6E - 110 - 'n'  **/
const __flash uint8_t Font08px_ln[5] = {4,
                                        bits2bytes(1, 1, 1, 1, 1, 0, 0, 0),
                                        bits2bytes(0, 0, 0, 1, 0, 0, 0, 0),
                                        bits2bytes(0, 0, 0, 0, 1, 0, 0, 0),
                                        bits2bytes(1, 1, 1, 1, 0, 0, 0, 0)};

/**  0x6F - 111 - 'o'  **/
const __flash uint8_t Font08px_lo[5] = {4,
                                        bits2bytes(0, 1, 1, 1, 0, 0, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 1, 0, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 1, 0, 0, 0),
                                        bits2bytes(0, 1, 1, 1, 0, 0, 0, 0)};

/**  0x70 - 112 - 'p'  **/
const __flash uint8_t Font08px_lp[5] = {4,
                                        bits2bytes(1, 1, 1, 1, 1, 0, 0, 0),
                                        bits2bytes(0, 0, 1, 0, 1, 0, 0, 0),
                                        bits2bytes(0, 0, 1, 0, 1, 0, 0, 0),
                                        bits2bytes(0, 0, 0, 1, 0, 0, 0, 0)};

/**  0x71 - 113 - 'q'  **/
const __flash uint8_t Font08px_lq[5] = {4,
                                        bits2bytes(0, 0, 0, 1, 0, 0, 0, 0),
                                        bits2bytes(0, 0, 1, 0, 1, 0, 0, 0),
                                        bits2bytes(0, 0, 1, 0, 1, 0, 0, 0),
                                        bits2bytes(1, 1, 1, 1, 1, 0, 0, 0)};

/**  0x72 - 114 - 'r'  **/
const __flash uint8_t Font08px_lr[4] = {3,
										bits2bytes(1, 1, 1, 1, 1, 0, 0, 0),
										bits2bytes(0, 0, 0, 1, 0, 0, 0, 0),
										bits2bytes(0, 0, 0, 0, 1, 0, 0, 0)};

/**  0x73 - 115 - 's'  **/
const __flash uint8_t Font08px_ls[5] = {4,
                                        bits2bytes(1, 0, 0, 1, 0, 0, 0, 0),
                                        bits2bytes(1, 0, 1, 0, 1, 0, 0, 0),
                                        bits2bytes(1, 0, 1, 0, 1, 0, 0, 0),
                                        bits2bytes(0, 1, 0, 0, 1, 0, 0, 0)};

/**  0x74 - 116 - 't'  **/
const __flash uint8_t Font08px_lt[4] = {3,
										bits2bytes(0, 0, 0, 0, 1, 0, 0, 0),
										bits2bytes(0, 1, 1, 1, 1, 1, 0, 0),
										bits2bytes(1, 0, 0, 0, 1, 0, 0, 0)};

/**  0x75 - 117 - 'u'  **/
const __flash uint8_t Font08px_lu[5] = {4,
                                        bits2bytes(0, 1, 1, 1, 1, 0, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 0, 0),
                                        bits2bytes(1, 1, 1, 1, 1, 0, 0, 0)};

/**  0x76 - 118 - 'v'  **/
const __flash uint8_t Font08px_lv[6] = {5,
                                        bits2bytes(0, 0, 0, 1, 1, 0, 0, 0),
                                        bits2bytes(0, 1, 1, 0, 0, 0, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 0, 0),
                                        bits2bytes(0, 1, 1, 0, 0, 0, 0, 0),
                                        bits2bytes(0, 0, 0, 1, 1, 0, 0, 0)};

/**  0x77 - 119 - 'w'  **/
const __flash uint8_t Font08px_lw[6] = {5,
                                        bits2bytes(0, 0, 1, 1, 1, 0, 0, 0),
                                        bits2bytes(1, 1, 0, 0, 0, 0, 0, 0),
                                        bits2bytes(0, 0, 1, 1, 0, 0, 0, 0),
                                        bits2bytes(1, 1, 0, 0, 0, 0, 0, 0),
                                        bits2bytes(0, 0, 1, 1, 1, 0, 0, 0)};

/**  0x78 - 120 - 'x'  **/
const __flash uint8_t Font08px_lx[6] = {5,
                                        bits2bytes(1, 0, 0, 0, 1, 0, 0, 0),
                                        bits2bytes(0, 1, 0, 1, 0, 0, 0, 0),
                                        bits2bytes(0, 0, 1, 0, 0, 0, 0, 0),
                                        bits2bytes(0, 1, 0, 1, 0, 0, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 1, 0, 0, 0)};

/**  0x79 - 121 - 'y'  **/
const __flash uint8_t Font08px_ly[5] = {4,
                                        bits2bytes(0, 0, 0, 1, 1, 0, 0, 0),
                                        bits2bytes(1, 0, 1, 0, 0, 0, 0, 0),
                                        bits2bytes(1, 0, 1, 0, 0, 0, 0, 0),
                                        bits2bytes(0, 1, 1, 1, 1, 0, 0, 0)};

/**  0x7A - 122 - 'z'  **/
const __flash uint8_t Font08px_lz[4] = {3,
										bits2bytes(1, 1, 0, 0, 1, 0, 0, 0),
										bits2bytes(1, 0, 1, 0, 1, 0, 0, 0),
										bits2bytes(1, 0, 0, 1, 1, 0, 0, 0)};

/** 0x7B - 123 - '{'  **/
const __flash uint8_t Font08px_left_curly_b[4] = {3,
                                        bits2bytes(0, 0, 0, 1, 0, 0, 0, 0),
                                        bits2bytes(0, 1, 1, 0, 1, 1, 0, 0),
                                        bits2bytes(1, 0, 0, 0, 0, 0, 1, 0)};

/** 0x7C - 124 - '|'  **/
const __flash uint8_t Font08px_Vertical_bar[2] = {1,
                                        bits2bytes(1, 1, 1, 1, 1, 1, 1, 1)};

/** 0x7D - 125 - '}'  **/
const __flash uint8_t Font08px_right_curly_b[] = {3,
										bits2bytes(1, 0, 0, 0, 0, 0, 1, 0),
                                        bits2bytes(0, 1, 1, 0, 1, 1, 0, 0),
										bits2bytes(0, 0, 0, 1, 0, 0, 0, 0)};

/** 0x7E - 126 - '~'  **/
const __flash uint8_t Font08px_tilde[5] = {4,
                                        bits2bytes(0, 0, 0, 0, 0, 0, 1, 0),
                                        bits2bytes(0, 0, 0, 0, 0, 0, 0, 1),
                                        bits2bytes(0, 0, 0, 0, 0, 0, 1, 0),
                                        bits2bytes(0, 0, 0, 0, 0, 0, 0, 1)};

/*============================================*/
/*========= Character pointers table =========*/
/*============================================*/

const __flash uint8_t * const __flash  font_table[] = {
	//first 32 characters not printed
	//NUL - character
    //SOH - Start of heading
    //STX - Start of text
    //EOT - End of text
    //ETX - End of transmission
    //ENQ - Enquery
    //ACK - acknowledge
    //BEL -  Bell
    //BS  - Backspace
    //TAB - Horizontal tab
    //LF  - NL line fed, new line
    //VT  - Vertical tab
    //FF  - NPform feed, new page
    //CR  - Carriage return
    //SO  - Shift out
    //SI  - Shift in
    //DLE - Data link escape
    //DC1 - Device control 1
    //DC2 - Device control 2
    //DC3 - Device control 3
    //DC4 - Device control 4
    //NAK - Negative acknowledge
    //SYN - Synchronous idle
    //ETB - End of trans. block
    //CAN - Cancel
    //EM  - End of medium
    //SUB - Substitute
    //ESC - Escape
    //FS  - File separator
    //GS  - Group separator
    //RS  - Record separator
    //US  - Unit separator
	Font08px_space,
    Font08px_exclemation,
    Font08px_quotation,
    Font08px_hash,
    Font08px_dollar,
    Font08px_percentage,
    Font08px_and,
    Font08px_apostrophe,
    Font08px_parentheses,
    Font08px_closing_parentheses,
    Font08px_star,
    Font08px_plus,
    Font08px_comma,
    Font08px_minus,
    Font08px_period,
    Font08px_slash,
    Font08px_N0,
    Font08px_N1,
    Font08px_N2,
    Font08px_N3,
    Font08px_N4,
    Font08px_N5,
    Font08px_N6,
    Font08px_N7,
    Font08px_N8,
    Font08px_N9,
    Font08px_colon,
    Font08px_semicolon,
    Font08px_les_than,
    Font08px_equals,
    Font08px_more_than,
    Font08px_questionmark,
    Font08px_curlya,
    Font08px_UA,
    Font08px_UB,
    Font08px_UC,
    Font08px_UD,
    Font08px_UE,
    Font08px_UF,
    Font08px_UG,
    Font08px_UH,
    Font08px_UI,
    Font08px_UJ,
    Font08px_UK,
    Font08px_UL,
    Font08px_UM,
    Font08px_UN,
    Font08px_UO,
    Font08px_UP,
    Font08px_UQ,
    Font08px_UR,
    Font08px_US,
    Font08px_UT,
    Font08px_UU,
    Font08px_UV,
    Font08px_UW,
    Font08px_UX,
    Font08px_UY,
    Font08px_UZ,
    Font08px_left_square_bracket,
    Font08px_backslash,
    Font08px_right_square_bracket,
    Font08px_caret,
    Font08px_underscore,
    Font08px_grave_acent,
    Font08px_la,
    Font08px_lb,
    Font08px_lc,
    Font08px_ld,
    Font08px_le,
    Font08px_lf,
    Font08px_lg,
    Font08px_lh,
    Font08px_li,
    Font08px_lj,
    Font08px_lk,
    Font08px_ll,
    Font08px_lm,
    Font08px_ln,
    Font08px_lo,
    Font08px_lp,
    Font08px_lq,
    Font08px_lr,
    Font08px_ls,
    Font08px_lt,
    Font08px_lu,
    Font08px_lv,
    Font08px_lw,
    Font08px_lx,
    Font08px_ly,
    Font08px_lz,
	Font08px_left_curly_b,
    Font08px_Vertical_bar,
    Font08px_right_curly_b,
	Font08px_tilde
};
