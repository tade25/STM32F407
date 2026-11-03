#include <stdint.h>
#include "led.h"
#include "timer.h"
#include "mcu.h"
#include "delay.h"
#include "pwm.h"

#define RCC_AHB1ENR ((uint32_t*)(0x40023800 + 0x30))
#define RCC_APB1ENR	((uint32_t*)(0x40023800 + 0x40))

int main(void)
{
	uint32_t reg_value = 0;

	Clock_Init();
	
	reg_value = *RCC_AHB1ENR;
	*RCC_AHB1ENR = reg_value | (1 << 0);

	reg_value = *RCC_APB1ENR;
	*RCC_APB1ENR = reg_value | (1 << 0) | (1 << 1) | (1 << 4);
	
	Delay_Init();
	Led_Init();
	PWM_Init();
	
	while(1) {
		Led_Off();
		delay_ms(1000);
		Led_On();
		delay_ms(1000);
		PWM_SetPeriodAndDuty(12800, 30);
	}
}