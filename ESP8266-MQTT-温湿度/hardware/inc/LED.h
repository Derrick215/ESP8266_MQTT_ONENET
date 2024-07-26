#ifndef __LED_H__
#define __LED_H__

typedef struct
{

	_Bool LED_Status;

} LED_INFO;

extern LED_INFO LED_info;

#define LED_ON		1

#define LED_OFF		0

void LED_Init(void);
void LED1_TURN(void);
void LED1_Set(_Bool status);
void LED_Run(void);


#endif
