#ifndef __GPIO_H_
#define __GPIO_H_

#include <stdint.h>

#define GPIOA_BASE	((uint32_t)0x40020000)
#define GPIOB_BASE	((uint32_t)0x40020400)
#define GPIOC_BASE	((uint32_t)0x40020800)
#define GPIOD_BASE	((uint32_t)0x40020C00)
#define GPIOE_BASE	((uint32_t)0x40021000)
#define GPIOF_BASE	((uint32_t)0x40021400)
#define GPIOG_BASE	((uint32_t)0x40021800)
#define GPIOH_BASE	((uint32_t)0x40021C00)
#define GPIOI_BASE	((uint32_t)0x40022000)
#define GPIOJ_BASE	((uint32_t)0x40022400)
#define GPIOK_BASE	((uint32_t)0x40022800)

typedef struct {
	uint32_t MODER;
	uint32_t OTYPER;
	uint32_t OSPEEDR;
	uint32_t PUPDR;
	uint32_t IDR;
	uint32_t ODR;
	uint32_t BSRR;
	uint32_t LCKR;
	uint32_t AFRL;
	uint32_t AFRH;
}GPIO_TypeDef;

#define GPIOA	(GPIO_TypeDef*)GPIOA_BASE
#define GPIOB	(GPIO_TypeDef*)GPIOB_BASE
#define GPIOC	(GPIO_TypeDef*)GPIOC_BASE
#define GPIOD	(GPIO_TypeDef*)GPIOD_BASE
#define GPIOE	(GPIO_TypeDef*)GPIOE_BASE
#define GPIOF	(GPIO_TypeDef*)GPIOF_BASE
#define GPIOG	(GPIO_TypeDef*)GPIOG_BASE
#define GPIOH	(GPIO_TypeDef*)GPIOH_BASE
#define GPIOI	(GPIO_TypeDef*)GPIOI_BASE
#define GPIOJ	(GPIO_TypeDef*)GPIOJ_BASE
#define GPIOK	(GPIO_TypeDef*)GPIOK_BASE

typedef enum {
    GPIO_MODE_IN     = 0,
    GPIO_MODE_OUT    = 1,
    GPIO_MODE_AF     = 2,
    GPIO_MODE_ANALOG = 3,
}GPIO_Mode;

typedef enum {
    GPIO_OTYPE_PP = 0,
    GPIO_OTYPE_OD = 1,
}GPIO_OType;

typedef enum {
    GPIO_SPEED_LOW        = 0,
    GPIO_SPEED_MEDIUM     = 1,
    GPIO_SPEED_HIGH       = 2,
    GPIO_SPEED_VERY_HIGH  = 3,
} GPIO_Speed;

typedef enum {
    GPIO_PUPD_NONE = 0,
    GPIO_PUPD_PU   = 1,
    GPIO_PUPD_PD   = 2,
} GPIO_Pupd;

typedef struct {
    GPIO_Mode	Mode;
    GPIO_OType	OType;
    GPIO_Speed	Speed;
    GPIO_Pupd	PuPd;
    uint8_t		Pin;
	uint8_t		AF;
}GPIO_InitTypeDef;

extern void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* InitStruct);

static inline void GPIO_SetPin(GPIO_TypeDef* GPIOx, uint8_t Pin)
{
    GPIOx->BSRR = (1U << Pin);
}

static inline void GPIO_ResetPin(GPIO_TypeDef* GPIOx, uint8_t Pin)
{
    GPIOx->BSRR = (1U << (Pin + 16U));
}

#endif
