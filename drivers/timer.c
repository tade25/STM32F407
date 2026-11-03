#include "timer.h"

void TIM_Base_Init(TIM_TypeDef* TIMx, TIM_BaseConf* conf)
{
	TIMx->PSC = (conf->Prescaler - 1);
	TIMx->ARR = (conf->Period - 1);
}

void TIM_Ch_PwmInit(TIM_TypeDef* TIMx, TIM_PwmConf* conf)
{
	uint32_t* pCCR = 0;
	uint32_t* ccmr = 0;
	uint32_t reg_val = 0;
	uint32_t shift = 0;

	if(conf->Channel > TIM_CH_4)
		return;

	if(conf->Channel < TIM_CH_3) {
		ccmr = &TIMx->CCMR1;
	}else {
		ccmr = &TIMx->CCMR2;
	}
	shift = (conf->Channel & 1U) ? 8U : 0U;
	pCCR = &TIMx->CCR1 + conf->Channel;

	*pCCR = conf->CCR;
	reg_val = *ccmr;
	reg_val &= ~((7 << (4 + shift)) | (1 << (3 + shift)));
	*ccmr = reg_val | (6 << (4 + shift)) | (1 << (3 + shift));
	reg_val = TIMx->CCER;
	reg_val &= ~(0xF << (4 * conf->Channel));
	TIMx->CCER = reg_val | (1 << (4 * conf->Channel)) | (conf->Polarity << (1 + 4 * conf->Channel));
}

void TIM_SetAutoreload(TIM_TypeDef* TIMx, uint32_t autoreload)
{
    TIMx->ARR = autoreload;
}

void TIM_PrescalerConfig(TIM_TypeDef* TIMx, uint16_t prescaler)
{
    TIMx->PSC = prescaler;
}

void TIM_SetCompare(TIM_TypeDef* TIMx, TIM_Channel channel, uint32_t compare)
{
	uint32_t* pCCR = 0;

	if(channel >= TIM_CH_MAX)
		return;
	
	pCCR = &TIMx->CCR1 + channel;
    *pCCR = compare;
}
