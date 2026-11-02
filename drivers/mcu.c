#include "mcu.h"

void Clock_Init(void)
{
	uint16_t timeout = 1000;
	RCC_TypeDef* rcc = RCC;

	/* 168MHz needs 5 Flash wait states before clock switch */
	FLASH_ACR = (FLASH_ACR & ~0x07U) | 0x05U;
	
	rcc->CR |= (1 << 0);
	while(0 == (rcc->CR & (1 << 1)));
	rcc->CFGR = 0;
	rcc->CR &= ~(1 << 16);
	rcc->CR &= ~(1 << 24);
	while(0 != (rcc->CR & (1 << 25)));
	rcc->PLLCFGR = 0x24003010;
	
	// 打开HSE
	rcc->CR |= (1 << 16);
	do {
		timeout--;
	}while((0 == (rcc->CR & (1 << 17))) && (timeout > 0));
	
	if(0 == timeout) {
		while(1);
	}
	
	// 配置PLL并打开
	rcc->PLLCFGR = (8 << 0) | (336 << 6) | (0 << 16) | (1 << 22) | (7 << 24);
	rcc->CR |= (1 << 24);
	while(0 == (rcc->CR & (1 << 25)));
	
	// 配置AHB和APB分频
	rcc->CFGR |= (0 << 4) | (5 << 10) | (4 << 13);
	
	// 切换系统时钟为PLL
	rcc->CFGR &= ~(3 << 0);
	rcc->CFGR |= (2 << 0);
	while((2 << 2) != (rcc->CFGR & (3 << 2)));
}
