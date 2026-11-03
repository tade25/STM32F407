#include "timer.h"
#include "gpio.h"

static uint8_t Pwm_LastDuty = 0;
static uint32_t Pwm_LastFreq = 0;

void PWM_Init(void)
{
    GPIO_InitTypeDef Gpio_InitStruct = {
        .Af = GPIO_AF_2,
        .Mode = GPIO_MODE_AF,
        .OType = GPIO_OTYPE_PP,
        .Pin = GPIO_PIN_7,
        .PuPd = GPIO_PUPD_NONE,
        .Speed = GPIO_SPEED_HIGH,
    };
    TIM_BaseConf Tim_InitBase = {
        .Period = 1000,
        .Prescaler = 84,
    };
    TIM_PwmConf Pwm_InitConfig = {
        .CCR = 0,
        .Channel = TIM_CH_2,
        .Polarity = TIM_Polarity_High,
    };

    // 简单的PWM输出
    GPIO_Init(GPIOA, &Gpio_InitStruct);
    TIM_Base_Init(TIM3, &Tim_InitBase);
    TIM_Ch_PwmInit(TIM3, &Pwm_InitConfig);
    TIM_Start(TIM3);
}

void PWM_SetPeriodAndDuty(uint32_t freq, uint8_t duty)
{
    uint32_t psc = 0;
    uint32_t arr = 0;
    float duty_cycle = 0.0;

    if((Pwm_LastFreq == freq) && (Pwm_LastDuty == duty))
        return;

    psc = (84000000 + 65535 * freq - 1) / (65535 * freq);
    arr = (84000000 + psc * freq / 2) / (psc * freq);
    duty_cycle = (float)duty / 100;

    TIM_SetAutoreload(TIM3, (arr - 1));
    TIM_PrescalerConfig(TIM3, (psc - 1));
    TIM_SetCompare(TIM3, TIM_CH_2, (uint32_t)(duty_cycle * arr));
    Pwm_LastFreq = freq;
    Pwm_LastDuty = duty;
}
