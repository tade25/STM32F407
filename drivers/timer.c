#include "timer.h"

void TIM_Base_Init(TIM_TypeDef* TIMx, TIM_BaseConf *conf)
{
	TIMx->PSC = (conf->Prescaler - 1);
	TIMx->ARR = (conf->Period - 1);
}
