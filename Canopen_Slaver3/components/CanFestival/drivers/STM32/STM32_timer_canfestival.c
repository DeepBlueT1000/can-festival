#include <stm32f10x.h>
#include <stdbool.h>
#include "canfestival.h"
#include "timer_canfestival.h"

/************************** Modul variables **********************************/
// Store the last timer value to calculate the elapsed time
static TIMEVAL last_time_set = TIMEVAL_MAX;
__IO uint16_t CCR1_Val = 49152;

void setTimer(TIMEVAL value)
{
	uint16_t capture = 0;
	capture = TIM_GetCapture1(TIM4);
	TIM_SetCompare1(TIM4, capture + value);
}

TIMEVAL getElapsedTime(void)
{
	uint16_t timer = TIM_GetCounter(TIM4);
  /* Calculate the time difference */
  /* return timer > last_time_set ? timer - last_time_set : last_time_set - timer; */
	/* I think this should be fixed to
	   16 bit substraction */
	timer = timer - last_time_set;		
	return timer;
}

/* TIM4 configure */
static void TIM4_Configuration(void)
{
	/* ʱ�Ӽ���Ƶ���� */
  {
  	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    /* Time Base configuration */
    /* 72M / 72 = 1us */
    TIM_TimeBaseStructure.TIM_Prescaler = 72 - 1;
    //����ģʽ:���ϼ���
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseStructure.TIM_Period = 0xFFFF;
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    //���¼�������ʼֵ
    TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;

    TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
	}

	{
		TIM_OCInitTypeDef  TIM_OCInitStructure;

		/* Output Compare Timing Mode configuration: Channel1 */
		TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Timing;
		TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
		TIM_OCInitStructure.TIM_Pulse = CCR1_Val;
		TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

		TIM_OC1Init(TIM4, &TIM_OCInitStructure);
		TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Disable);
	}

	/* TIM IT enable */
	TIM_ITConfig(TIM4, TIM_IT_CC1, ENABLE);

  /* TIM enable counter */
  TIM_Cmd(TIM4, ENABLE);
}

static void NVIC_Configuration(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;

    /* Enable the TIM4 global Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

static void RCC_Configuration(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);

  /* TIM4 clock enable */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);

  /* clock enable */
  RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA ,ENABLE);
}

void TIM4_start(void)
{
  RCC_Configuration();

  /* configure TIM4 for remote and encoder */
  NVIC_Configuration();
  TIM4_Configuration();
}

void TIM4_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM4, TIM_IT_CC1) != RESET)
	{
		TIM_ClearITPendingBit(TIM4, TIM_IT_CC1);
		last_time_set = TIM_GetCounter(TIM4);
		TimeDispatch();
	}
}
