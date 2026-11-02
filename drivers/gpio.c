#include "gpio.h"

void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* InitStruct)
{
	uint8_t pin = InitStruct->Pin;
	uint8_t bit2 = 2 * pin;
	uint8_t bit1 = 1 * pin;
	
	
	GPIOx->MODER	&= ~(0x03 << bit2);
	GPIOx->OTYPER	&= ~(0x01 << bit1);
	GPIOx->OSPEEDR	&= ~(0x03 << bit2);
	GPIOx->PUPDR	&= ~(0x03 << bit2);
	
	GPIOx->MODER	|= (InitStruct->Mode << bit2);
	GPIOx->OTYPER	|= (InitStruct->OType << bit1);
	GPIOx->OSPEEDR	|= (InitStruct->Speed << bit2);
	GPIOx->PUPDR	|= (InitStruct->PuPd << bit2);
}
