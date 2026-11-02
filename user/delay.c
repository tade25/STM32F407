#include "timer.h"

#define DELAY_TIMER	TIM6

void Delay_Init(void)
{
	TIM_BaseConf Delay_InitConf;
	
	Delay_InitConf.Period = 65535;
	Delay_InitConf.Prescaler = 42;
	TIM_Base_Init(DELAY_TIMER, &Delay_InitConf);
	TIM_Start(DELAY_TIMER);
}

void delay_us(uint32_t us)
{
	uint32_t start = 0;
	
	start = TIM_GetCnt(DELAY_TIMER);
	while((TIM_GetCnt(DELAY_TIMER) - start) < us) {
		;
	}
}

void delay_ms(uint32_t ms)
{
	uint32_t cnt = 0;
	
	for(cnt = 0;cnt < ms;cnt++)
		delay_us(1000);
}
