#ifndef __MCU_H_
#define __MCU_H_

#include <stdint.h>

typedef struct {
	uint32_t CR;
	uint32_t PLLCFGR;
	uint32_t CFGR;
	uint32_t CIR;
	uint32_t AHB1RSTR;
	uint32_t AHB2RSTR;
	uint32_t AHB3RSTR;
	uint32_t reserved_0;
	uint32_t APB1RSTR;
	uint32_t APB2RSTR;
	uint32_t reserved_1;
	uint32_t reserved_2;
	uint32_t AHB1ENR;
	uint32_t AHB2ENR;
	uint32_t AHB3ENR;
	uint32_t reserved_3;
	uint32_t APB1ENR;
	uint32_t APB2ENR;
	uint32_t reserved_4;
	uint32_t reserved_5;
	uint32_t AHB1LPENR;
	uint32_t AHB2LPENR;
	uint32_t AHB3LPENR;
	uint32_t reserved_6;
	uint32_t APB1LPENR;
	uint32_t APB2LPENR;
	uint32_t reserved_7;
	uint32_t reserved_8;
	uint32_t BDCR;
	uint32_t CSR;
	uint32_t reserved_9;
	uint32_t reserved_10;
	uint32_t SSCGR;
	uint32_t PLLI2SCFGR;
}RCC_TypeDef;

#define RCC_BASE ((uint32_t)0x40023800)
#define RCC	(RCC_TypeDef*)RCC_BASE

#define FLASH_ACR	(*(volatile uint32_t*)0x40023C00)

extern void Clock_Init(void);

#endif
