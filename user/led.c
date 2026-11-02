#include "gpio.h"
#include "led.h"

void Led_Init(void)
{
	GPIO_InitTypeDef Led_InitStruct;
	
	Led_InitStruct.Pin = 6;
	Led_InitStruct.Mode = GPIO_MODE_OUT;
	Led_InitStruct.OType = GPIO_OTYPE_PP;
	Led_InitStruct.Speed = GPIO_SPEED_HIGH;
	Led_InitStruct.PuPd = GPIO_PUPD_NONE;
	GPIO_Init(GPIOA, &Led_InitStruct);
	
	Led_InitStruct.Pin = 7;
	GPIO_Init(GPIOA, &Led_InitStruct);
}

void Led_On(void)
{
	GPIO_ResetPin(GPIOA, 6);
	GPIO_ResetPin(GPIOA, 7);
}

void Led_Off(void)
{
	GPIO_SetPin(GPIOA, 6);
	GPIO_SetPin(GPIOA, 7);
}
