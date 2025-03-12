/**
  ******************************************************************************
  * @file    main.h
  * @author  MCU Application Team
  * @brief   Header for main.c file.
  *          This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) Puya Semiconductor Co.
  * All rights reserved.</center></h2>
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32f0xx_hal.h"
#include "py32f030xx_Start_Kit.h"

/* Private includes ----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
//#define led_A GPIO_PIN_1
//#define led_B GPIO_PIN_1
//#define led_C GPIO_PIN_15
//#define led_D GPIO_PIN_0
//#define led_E GPIO_PIN_6
//#define led_F GPIO_PIN_0
//#define led_G GPIO_PIN_5

//#define DIGIT_1 GPIO_PIN_2  // V? trí LED 1
//#define DIGIT_2 GPIO_PIN_3  // V? trí LED 2
//#define DIGIT_3 GPIO_PIN_4  // V? trí LED 3
/* Exported variables prototypes ---------------------------------------------*/
/* Exported functions prototypes ---------------------------------------------*/
void APP_ErrorHandler(void);

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
