#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"
#include "SerialA.h"
#include "Motor.h"
#include "MotorA.h"
#include "Servo.h"
#include "string.h"
#include "pwmA.h"
#include "PID.H"
#include  "ENCODER.H"
#include "stdio.h"

uint8_t RxData;
int16_t speed,time=0,tar=10;

int main(void)
{
	MotorA_Init();
	Encoder1_Init();
	Serial_Init();
	Delay_ms(10);
	SerialA_Init();
	Delay_ms(10);
	Motor_Init();
	Servo_Init();
	Delay_ms(10);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	while (1)
	{
		Servo_SetAngle(110);
		if (Serial_RxFlag == 1)
		{			
			if (strcmp(Serial_RxPacket, "A") == 0)
			{
				Servo_SetAngle(110);
				Serial_SendString("A");
			}
			else if (strcmp(Serial_RxPacket, "B") == 0)
			{
				Servo_SetAngle(140);						
				Serial_SendString("B");
			}
			else if (strcmp(Serial_RxPacket, "C") == 0)
			{
				Motor_SetSpeed(95);	
				Serial_SendString("C");	
			}
			else if (strcmp(Serial_RxPacket, "D") == 0)
			{
				Motor_SetSpeed(0);				
				Serial_SendString("D");
			}
			else if (strcmp(Serial_RxPacket, "E") == 0)
			{
				right_f(pid1(speed,tar));
			}
			else if (strcmp(Serial_RxPacket, "F") == 0)
			{
				right_f(pid1(speed,0));	
			}
			else if (strcmp(Serial_RxPacket, "G") == 0)
			{
				SerialA_SendString("@A\r\n");
			}
			else if (strcmp(Serial_RxPacket, "H") == 0)
			{
				SerialA_SendString("@B\r\n");	
			}
			else if (strcmp(Serial_RxPacket, "I") == 0)
			{
				SerialA_SendString("@C\r\n");	
			}
			else if (strcmp(Serial_RxPacket, "J") == 0)
			{
				SerialA_SendString("@D\r\n");	
			}
			else if (strcmp(Serial_RxPacket, "K") == 0)
			{
				SerialA_SendString("@E\r\n");	
			}
			else if (strcmp(Serial_RxPacket, "L") == 0)
			{
				SerialA_SendString("@F\r\n");	
			}
			else if (strcmp(Serial_RxPacket, "M") == 0)
			{
				SerialA_SendString("@G\r\n");	
			}
			else if (strcmp(Serial_RxPacket, "N") == 0)
			{
				SerialA_SendString("@H\r\n");	
			}
			else if (strcmp(Serial_RxPacket, "O") == 0)
			{
				SerialA_SendString("@I\r\n");	
			}
			else if (strcmp(Serial_RxPacket, "P") == 0)
			{
				SerialA_SendString("@J\r\n");	
			}
			Serial_RxFlag = 0;
		}
	}
}
void TIM4_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM4, TIM_IT_Update) == SET)
	{
        time++;
        if(time==10)
        {
            speed=Encoder1_get();
            time=0;
        }
		TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
	}
}
