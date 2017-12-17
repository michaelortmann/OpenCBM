/**
  ******************************************************************************
  * File Name          : stm32f1xx_hal_msp.c
  * Description        : This file provides code for the MSP Initialization 
  *                      and de-Initialization codes.
  ******************************************************************************
  *
  * Copyright (c) 2017 STMicroelectronics International N.V. 
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

//extern void Error_Handler(void);
extern void _Error_Handler(char * file, int line);
/* USER CODE BEGIN 0 */

//#include "board.h"
#include "xuac.h" // the inventory

/* USER CODE END 0 */
/**
  * Initializes the Global MSP.
  */
void HAL_MspInit(void)
{
  __HAL_RCC_AFIO_CLK_ENABLE();

  HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

  /* System interrupt init*/
  /* MemoryManagement_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(MemoryManagement_IRQn, 0, 0);
  /* BusFault_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(BusFault_IRQn, 0, 0);
  /* UsageFault_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(UsageFault_IRQn, 0, 0);
  /* SVCall_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SVCall_IRQn, 0, 0);
  /* DebugMonitor_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DebugMonitor_IRQn, 0, 0);
  /* PendSV_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(PendSV_IRQn, 0, 0);
  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);

  /**NOJTAG: JTAG-DP Disabled and SW-DP Enabled
  */
  __HAL_AFIO_REMAP_SWJ_NOJTAG();
}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef* htim)
{
	if ((xuac->Board_HW->data->CfgMode == tape_cfg_capture)
		|| (xuac->Board_HW->data->CfgMode == tape_cfg_write))
	{
		xuac->Board_HW->Tape->HAL_TIM_Base_MspInit(htim);
	}
}

void HAL_TIM_MspPostInit(TIM_HandleTypeDef* htim)
{
	if ((xuac->Board_HW->data->CfgMode == tape_cfg_capture)
		|| (xuac->Board_HW->data->CfgMode == tape_cfg_write))
	{
		xuac->Board_HW->Tape->HAL_TIM_MspPostInit(htim);
	}
}

void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef* htim)
{
	if ((xuac->Board_HW->data->CfgMode == tape_cfg_capture)
		|| (xuac->Board_HW->data->CfgMode == tape_cfg_write))
	{
		xuac->Board_HW->Tape->HAL_TIM_Base_MspDeInit(htim);
	}
}

void HAL_TIM_IC_MspDeInit(TIM_HandleTypeDef *htim)
{
	if (xuac->Board_HW->data->CfgMode == tape_cfg_capture)
	{
		xuac->Board_HW->Tape->HAL_TIM_IC_MspDeInit(htim);
	}
}

void HAL_TIM_OC_MspDeInit(TIM_HandleTypeDef *htim)
{
	if (xuac->Board_HW->data->CfgMode == tape_cfg_write)
	{
		xuac->Board_HW->Tape->HAL_TIM_OC_MspDeInit(htim);
	}
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
