#include "gpio.h"

void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* InitStruct)
{
	uint32_t* pAFR = 0;
	uint32_t reg_value = 0;
	uint32_t shift = 0;
	uint8_t pin = InitStruct->Pin;
	uint8_t bit2 = 2 * pin;
	
	if((pin >= GPIO_PIN_MAX) || (InitStruct->Af >= GPIO_AF_MAX))
		return;

	if(pin < GPIO_PIN_8) {
		pAFR = &GPIOx->AFRL;
		shift = 0;
	}else {
		pAFR = &GPIOx->AFRH;
		shift = GPIO_PIN_8;
	}

	GPIOx->OTYPER	&= ~(0x01 << pin);
	GPIOx->OSPEEDR	&= ~(0x03 << bit2);
	GPIOx->PUPDR	&= ~(0x03 << bit2);
	
	GPIOx->OTYPER	|= (InitStruct->OType << pin);
	GPIOx->OSPEEDR	|= (InitStruct->Speed << bit2);
	GPIOx->PUPDR	|= (InitStruct->PuPd << bit2);

	if(GPIO_MODE_AF == InitStruct->Mode) {
		reg_value = *pAFR;
		reg_value &= ~(0xF << (4 * (pin - shift)));
		*pAFR = reg_value | (uint32_t)(InitStruct->Af << (4 * (pin - shift)));
	}

	GPIOx->MODER	&= ~(0x03 << bit2);
	GPIOx->MODER	|= (InitStruct->Mode << bit2);
}
