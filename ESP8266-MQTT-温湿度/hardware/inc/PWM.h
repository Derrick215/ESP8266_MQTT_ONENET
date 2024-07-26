#ifndef __PWM_H
#define __PWM_H

void PWM_Init(uint16_t TIM_Period, uint16_t TIM_Prescaler);
void PWM_SetCompare3(uint16_t Compare);

#endif
