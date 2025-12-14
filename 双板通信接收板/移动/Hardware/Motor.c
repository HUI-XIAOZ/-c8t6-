#include "stm32f10x.h"                  // Device header
#include "PWM.h"
void Motor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	PWM_Init();
}

void FLMotor_Speed(int8_t Speed)
{
	if (Speed >0)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_10);
		GPIO_ResetBits(GPIOB, GPIO_Pin_11);
		PWM_SetCompare1(Speed);
	}
	else if(Speed==0){
		GPIO_SetBits(GPIOB, GPIO_Pin_10);
		GPIO_SetBits(GPIOB, GPIO_Pin_11);
		PWM_SetCompare1(Speed);
	}else{
		GPIO_ResetBits(GPIOB, GPIO_Pin_10);
		GPIO_SetBits(GPIOB, GPIO_Pin_11);
		PWM_SetCompare1(-Speed);
	}
}

void FRMotor_Speed(int8_t Speed)
{
	if (Speed >0)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_12);
		GPIO_ResetBits(GPIOB, GPIO_Pin_13);
		PWM_SetCompare4(Speed);
	}
	else if(Speed==0){
		GPIO_SetBits(GPIOB, GPIO_Pin_12);
		GPIO_SetBits(GPIOB, GPIO_Pin_13);
		PWM_SetCompare4(Speed);
	}else{
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);
		GPIO_SetBits(GPIOB, GPIO_Pin_13);
		PWM_SetCompare4(-Speed);
	}
}

void RLMotor_Speed(int8_t Speed)
{
	if (Speed >0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_11);
		GPIO_ResetBits(GPIOA, GPIO_Pin_12);
		PWM_SetCompare2(Speed);
	}
	else if(Speed==0){
		GPIO_SetBits(GPIOA, GPIO_Pin_11);
		GPIO_SetBits(GPIOA, GPIO_Pin_12);
		PWM_SetCompare2(Speed);
	}else{
		GPIO_ResetBits(GPIOA, GPIO_Pin_11);
		GPIO_SetBits(GPIOA, GPIO_Pin_12);
		PWM_SetCompare2(-Speed);
	}
}
void RRMotor_Speed(int8_t Speed)
{
	if (Speed >0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_6);
		GPIO_ResetBits(GPIOA, GPIO_Pin_7);
		PWM_SetCompare3(Speed);
	}
	else if(Speed==0){
		GPIO_SetBits(GPIOA, GPIO_Pin_6);
		GPIO_SetBits(GPIOA, GPIO_Pin_7);
		PWM_SetCompare3(Speed);
	}else{
		GPIO_ResetBits(GPIOA, GPIO_Pin_6);
		GPIO_SetBits(GPIOA, GPIO_Pin_7);
		PWM_SetCompare3(-Speed);
	}
}
