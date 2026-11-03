#ifndef __TIMER_H_
#define __TIMER_H_

#include <stdint.h>

#define TIM2_BASE	((uint32_t)0x40000000)
#define TIM6_BASE	((uint32_t)0x40001000)

typedef struct {
	uint32_t CR1;
	uint32_t CR2;
	uint32_t SMCR;
	uint32_t DIER;
	uint32_t SR;
	uint32_t EGR;
	uint32_t CCMR1;
	uint32_t CCMR2;
	uint32_t CCER;
	uint32_t CNT;
	uint32_t PSC;
	uint32_t ARR;
	uint32_t reserved_0;
	uint32_t CCR1;
	uint32_t CCR2;
	uint32_t CCR3;
	uint32_t CCR4;
	uint32_t reserved_1;
	uint32_t DCR;
	uint32_t DMAR;
	uint32_t TIM2_OR;
	uint32_t TIM5_OR;
}TIM_TypeDef;

#define TIM2	(TIM_TypeDef*)TIM2_BASE
#define TIM6	(TIM_TypeDef*)TIM6_BASE

typedef struct {
	uint32_t Period;
	uint32_t Prescaler;
} TIM_BaseConf;

typedef enum {
	TIM_CH_1 = 0,
	TIM_CH_2,
	TIM_CH_3,
	TIM_CH_4
} TIM_Channel;

typedef enum {
	TIM_Polarity_High = 0,
	TIM_Polarity_Low,
} TIM_Polarity;

typedef struct {
	uint32_t		CCR;
	TIM_Channel		Channel;
	TIM_Polarity	Polarity;
}TIM_PwmConf;

static inline void TIM_Start(TIM_TypeDef* TIMx)
{
	TIMx->CR1 |= (1 << 0);
}

static inline void TIM_Stop(TIM_TypeDef* TIMx)
{
	TIMx->CR1 &= ~(1 << 0);
}

static inline void TIM_CntClear(TIM_TypeDef* TIMx)
{
	TIMx->CNT = 0;
}

static inline uint32_t TIM_GetCnt(TIM_TypeDef* TIMx)
{
	return TIMx->CNT;
}

extern void TIM_Base_Init(TIM_TypeDef* TIMx, TIM_BaseConf* conf);
extern void TIM_Ch_PwmInit(TIM_TypeDef* TIMx, TIM_PwmConf* conf);
extern void delay_us(uint32_t us);
extern void delay_ms(uint32_t ms);

#endif
