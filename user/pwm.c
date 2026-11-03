#include "timer.h"
#include "gpio.h"

void PWM_Init(void)
{
    GPIO_InitTypeDef Gpio_InitStruct = {
        .Af = GPIO_AF_1,
        .Mode = GPIO_MODE_AF,
        .OType = GPIO_OTYPE_PP,
        .Pin = GPIO_PIN_1,
        .PuPd = GPIO_PUPD_NONE,
        .Speed = GPIO_SPEED_HIGH,
    };
    TIM_BaseConf Tim_InitBase = {
        .Period = 1000,
        .Prescaler = 84,
    };
    TIM_PwmConf Pwm_InitConfig = {
        .CCR = 500,
        .Channel = TIM_CH_2,
        .Polarity = TIM_Polarity_High,
    };

    // 简单的PWM输出
    GPIO_Init(GPIOA, &Gpio_InitStruct);
    TIM_Base_Init(TIM2, &Tim_InitBase);
    TIM_Ch_PwmInit(TIM2, &Pwm_InitConfig);
    TIM_Start(TIM2);
}
