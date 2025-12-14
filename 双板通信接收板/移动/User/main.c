#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "CAR.h"
#include "Serial.h"
#include "Servo.h"
#include "string.h"

uint8_t RxData;			//?????????????

int main(void)
{ 
	Car_Init();
	Serial_Init();
	Servo_Init();
	Servo_SetAngle(180);
	while (1)
	{
		if (Serial_RxFlag == 1)
		{			
			if (strcmp(Serial_RxPacket, "A") == 0)
			{
				Servo_SetAngle(110);
			}
			else if (strcmp(Serial_RxPacket, "B") == 0)
			{
				Servo_SetAngle(180);						
			}
			else if (strcmp(Serial_RxPacket, "C") == 0)
			{
				Go_Ahead();	
			}
			else if (strcmp(Serial_RxPacket, "D") == 0)
			{
				Go_Back();	
			}
			else if (strcmp(Serial_RxPacket, "E") == 0)
			{
				Car_Stop();	
			}
			else if (strcmp(Serial_RxPacket, "F") == 0)
			{
				Self_Left();	
			}
			else if (strcmp(Serial_RxPacket, "G") == 0)
			{
				Self_Right();	
			}
			else if (strcmp(Serial_RxPacket, "H") == 0)
			{
				ServoA_SetAngle(1000);	
			}
			else if (strcmp(Serial_RxPacket, "I") == 0)
			{
				ServoA_SetAngle(2000);	
			}
			else if (strcmp(Serial_RxPacket, "J") == 0)
			{
				ServoA_SetAngle(0);	
			}
			Serial_RxFlag = 0;
		}
	}
}
