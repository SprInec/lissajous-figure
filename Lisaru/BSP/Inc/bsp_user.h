/**
 ******************************************************************************
 * @file		:bsp_user.h
 * @project	:
 * @brief		:Project user files.
 * @version	:0.1.0
 * @author	:July
 * @date		:2022.06.27
 ******************************************************************************
 *@attention
 *
 * This file is a specific user file for a specific project.
 * Specific functions declaration within the project are located in this file.
 *
 ******************************************************************************
 */
 
#ifndef __BSP_USER_H__
#define __BSP_USER_H__

#include "bsp_config.h"

/* INCLUDE BEGIN */
#include "tim.h"
#include "usart.h"
#include "dac.h"
/* INCLUDE END */


/* MACRO DEFINITION BEGIN */

/*=========================*/
#define _AD9959_		0
#define _IT_TIMER_	1
#define _DAC_DMA_		1
/*=========================*/

#if			_AD9959_
#define LISARU_AMP			1023

#if			1
#define PHA_0						0
#define PHA_45					31
#define PHA_90					63
#define PHA_135					95
#define PHA_180					127
#elif 	0
#define PHA_0						0+455
#define PHA_45					2048+455
#define PHA_90					4096+455
#define PHA_135					6145+455
#define PHA_180					8193+455
#else		
#define PHA_0						0
#define PHA_45					2048
#define PHA_90					4096
#define PHA_135					6145
#define PHA_180					8193
#endif
#else  /* AD9833 */
#define LISARU_AMP			80

#define PHA_0						0
#define PHA_45					31
#define PHA_90					63
#define PHA_135					95
#define PHA_180					127

#define PHAx_0					0+455
#define PHAx_45					2048+455
#define PHAx_90					4096+455
#define PHAx_135				6145+455
#define PHAx_180				8193+455

#define PHAx2_0					4096+455
#define PHAx2_45				6145+455
#define PHAx2_90				8193+455
#define PHAx2_135				6145+455
#define PHAx2_180				4096+455

#define PHAx3_0					8193+455
#define PHAx3_45				6145+500
#define PHAx3_90				4096+1200
#define PHAx3_135				2048+1000
#define PHAx3_180				0+455

#define PHAx4_0					2048+455
#define PHAx4_45				4096+455
#define PHAx4_90				2048+455
#define PHAx4_135				0+455
#define PHAx4_180				2048+455
#endif

/* MACRO DEFINITION END */



/* STRUCT DEFINITION BEGIN */
typedef struct lisaru{
	uint32_t 	orifreq;
	uint32_t 	putfreq;
	uint16_t 	amp;
	uint16_t	pha;
}lisaru;
/* STRUCT DEFINITION END */



/* ENUM DEFINITION BEGIN */

/* ENUM DEFINITION END */



/* EXTERN VARIABLE DEFINITION BEGIN */
extern const  uint16_t Sine128bit_0[];
extern const uint16_t Sine256bit_0[];

extern const uint16_t Sine256bit_45[];
extern const uint16_t Sine256bit_90[];
extern const uint16_t Sine256bit_135[];
extern const uint16_t Sine256bit_180[];

extern lisaru lisa;
extern lisaru lisb;
/* EXTERN VARIABLE DEFINITION END */



/* FUNCTION DEFINITION BEGIN */
void bsp_Init(void);
void bsp_imag_select(void);
void bsp_lisaru_numalp(void);
void bsp_SwitchGate(void);
/* FUNCTION DEFINITION END */



#endif /* __BSP_USER_H__ */

