#ifndef __PWM_H_
#define __PWM_H_

#include <stdint.h>

extern void PWM_Init(void);
extern void PWM_SetPeriodAndDuty(uint32_t freq, uint8_t duty);

#endif
