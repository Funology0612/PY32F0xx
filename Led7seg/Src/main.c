/**
  ******************************************************************************
  * @file    main.c
  * @author  MCU Application Team
  * @brief   Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private define ------------------------------------------------------------*/
#define PORTA GPIOA
#define PORTB GPIOB
#define PORTF GPIOF

#define led_A GPIO_PIN_1
#define led_B GPIO_PIN_1
#define led_C GPIO_PIN_15
#define led_D GPIO_PIN_0
#define led_E GPIO_PIN_6
#define led_F GPIO_PIN_0
#define led_G GPIO_PIN_5

#define DIGIT_1 GPIO_PIN_4  // Vi trí LED 1
#define DIGIT_2 GPIO_PIN_3  // Vi trí LED 2
#define DIGIT_3 GPIO_PIN_2  // Vi trí LED 3
/* Private variables ---------------------------------------------------------*/

uint8_t code_seg[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
uint32_t counter;
void Display_Number(uint16_t num);
void Display_Digit(uint8_t digit, uint8_t value);

/* Private user code ---------------------------------------------------------*/

void Display_Number(uint16_t num)
{
    uint8_t hundreds = num / 100;      // Lấy hàng trăm
    uint8_t tens = (num / 10) % 10;    // Lấy hàng chục
    uint8_t units = num % 10;          // Lấy hàng đơn vị

    Display_Digit(1, hundreds);        // Hiển thị hàng trăm
    HAL_Delay(5);                          // Delay để quét LED
    Display_Digit(2, tens);            // Hiển thị hàng chục
    HAL_Delay(5);                          // Delay để quét LED
    Display_Digit(3, units);           // Hiển thị hàng đơn vị
    HAL_Delay(5);                           // Delay để quét LED
}

/* Hiển thị một số lên một LED 7 đoạn tại vị trí cụ thể */
void Display_Digit(uint8_t digit, uint8_t value)
{
    /* Tắt tất cả các vị trí trước khi bật vị trí mới */
    HAL_GPIO_WritePin(PORTA, DIGIT_1 | DIGIT_2 | DIGIT_3, GPIO_PIN_RESET);

    /* Chọn vị trí LED 7 đoạn cần hiển thị */
    switch (digit)
    {
        case 1:
            HAL_GPIO_WritePin(PORTA, DIGIT_1, GPIO_PIN_SET);
				    HAL_GPIO_WritePin(PORTA, DIGIT_2, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(PORTA, DIGIT_3, GPIO_PIN_RESET);

            break;
        case 2:
            HAL_GPIO_WritePin(PORTA, DIGIT_1, GPIO_PIN_RESET);
				    HAL_GPIO_WritePin(PORTA, DIGIT_2, GPIO_PIN_SET);
            HAL_GPIO_WritePin(PORTA, DIGIT_3, GPIO_PIN_RESET);
            break;
        case 3:
            HAL_GPIO_WritePin(PORTA, DIGIT_1, GPIO_PIN_RESET);
				    HAL_GPIO_WritePin(PORTA, DIGIT_2, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(PORTA, DIGIT_3, GPIO_PIN_SET);
            break;
        default:
            return;
    }

    /* Xuất dữ liệu lên LED 7 đoạn */
    uint8_t data = code_seg[value];

    HAL_GPIO_WritePin(PORTA, led_A, (data & 0x01) ? 1 : 0);
		HAL_GPIO_WritePin(PORTF, led_B, (data & 0x02) ? 1 : 0);
		HAL_GPIO_WritePin(PORTA, led_C, (data & 0x04) ? 1 : 0);
		HAL_GPIO_WritePin(PORTB, led_D, (data & 0x08) ? 1 : 0);
		HAL_GPIO_WritePin(PORTA, led_E, (data & 0x10) ? 1 : 0);
		HAL_GPIO_WritePin(PORTA, led_F, (data & 0x20) ? 1 : 0);
		HAL_GPIO_WritePin(PORTB, led_G, (data & 0x40) ? 1 : 0);
}


/* Private macro -------------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
static void APP_GpioConfig(void);
static void APP_SystemClockConfig(void);
static void MX_GPIO_Init(void);

/**
  * @brief  应用程序入口函数.
  * @retval int
  */
int main(void)
{
  /* 初始化所有外设，Flash接口，SysTick */
  HAL_Init();
	MX_GPIO_Init();	
  APP_SystemClockConfig();
  /* 初始化GPIO */
  APP_GpioConfig();

  while (1)
  {
//    Display_Number(counter);     // Hiển thị số hiện tại trên 3 LED 7 đoạn
//    counter++;                   // Tăng biến đếm
//    if (counter > 999) counter = 0; // Reset về 0 khi quá 999
//    HAL_Delay(500);
		for(counter = 0; counter < 1000; counter++)
		{
			for(int j = 0; j < 24; j++)
			{
				Display_Number(counter);     // Hiển thị số hiện tại trên 3 LED 7 đoạn
				//HAL_Delay(500);
			}
		}
	}
}
/**
  * @brief  GPIO配置
  * @param  无
  * @retval 无
  */

//HAL_StatusTypeDef HAL_Init(void)
//{
//  /* Configure Flash prefetch */ 
//#if (PREFETCH_ENABLE != 0)
//  __HAL_FLASH_PREFETCH_BUFFER_ENABLE();
//#endif /* PREFETCH_ENABLE */

//  /* Use systick as time base source and configure 1ms tick (default clock after Reset is HSI) */

//  HAL_InitTick(TICK_INT_PRIORITY);

//  /* Init the low level hardware */
//  HAL_MspInit();

//  /* Return function status */
//  return HAL_OK;
//}

static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOF_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_1, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_6|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_5, GPIO_PIN_RESET);

  /*Configure GPIO pin : PF1 */
  GPIO_InitStruct.Pin = GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /*Configure GPIO pins : PA0 PA1 PA2 PA3
                           PA4 PA6 PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_6|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB5 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

static void APP_GpioConfig(void)
{
  GPIO_InitTypeDef  GPIO_InitStruct;

  __HAL_RCC_GPIOA_CLK_ENABLE();                          /* 使能GPIOA时钟 */

  GPIO_InitStruct.Pin = GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;            /* 推挽输出 */
  GPIO_InitStruct.Pull = GPIO_PULLUP;                    /* 使能上拉 */
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;          /* GPIO速度 */  
  /* GPIO初始化 */
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);                
}

static void APP_SystemClockConfig(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /* 振荡器配置 */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE | RCC_OSCILLATORTYPE_HSI | RCC_OSCILLATORTYPE_LSI; /* 选择振荡器HSE,HSI,LSI */
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;                          /* 开启HSI */
  RCC_OscInitStruct.HSIDiv = RCC_HSI_DIV1;                          /* HSI 1分频 */
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_24MHz;  /* 配置HSI时钟8MHz */
  RCC_OscInitStruct.HSEState = RCC_HSE_OFF;                         /* 关闭HSE */
  /*RCC_OscInitStruct.HSEFreq = RCC_HSE_16_32MHz;*/
  RCC_OscInitStruct.LSIState = RCC_LSI_OFF;                         /* 关闭LSI */

  /* 配置振荡器 */
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    APP_ErrorHandler();
  }

  /* 时钟源配置 */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1; /* 选择配置时钟 HCLK,SYSCLK,PCLK1 */
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI; /* 选择HSI作为系统时钟 */
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;     /* AHB时钟 1分频 */
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;      /* APB时钟 1分频 */
  /* 配置时钟源 */
  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    APP_ErrorHandler();
  }
}
/**
  * @brief  错误执行函数
  * @param  无
  * @retval 无
  */
void APP_ErrorHandler(void)
{
  while (1)
  {
  }
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  输出产生断言错误的源文件名及行号
  * @param  file：源文件名指针
  * @param  line：发生断言错误的行号
  * @retval 无
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* 用户可以根据需要添加自己的打印信息,
     例如: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* 无限循环 */
  while (1)
  {
  }
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
