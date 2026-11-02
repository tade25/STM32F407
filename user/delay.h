#ifndef __DELAY_H_
#define __DELAY_H_

#include <stdint.h>

extern void Delay_Init(void);
extern void delay_us(uint32_t us);
extern void delay_ms(uint32_t ms);

#endif
