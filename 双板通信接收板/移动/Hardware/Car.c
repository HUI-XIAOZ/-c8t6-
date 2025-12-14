#include "stm32f10x.h"                  // Device header
#include "Motor.h"
#include "Delay.h"
void Car_Init(){
	Motor_Init();
}
void Go_Ahead(){
	FLMotor_Speed(80);
	FRMotor_Speed(80);
	RLMotor_Speed(80);
	RRMotor_Speed(80);
}
void Go_Back(){
	FLMotor_Speed(-80);
	FRMotor_Speed(-80);
	RLMotor_Speed(-80);
	RRMotor_Speed(-80);
}
void Turn_Left(){
	FLMotor_Speed(70);
	FRMotor_Speed(70);
	RLMotor_Speed(70);
	RRMotor_Speed(70);
}
void Turn_Right(){
	FLMotor_Speed(-70);
	FRMotor_Speed(-70);
	RLMotor_Speed(-70);
	RRMotor_Speed(-70);
	
}
void Self_Left(){
	FLMotor_Speed(-80);
	FRMotor_Speed(80);
	RLMotor_Speed(-80);
	RRMotor_Speed(80);
}
void Self_Right(){
	FLMotor_Speed(80);
	FRMotor_Speed(-80);
	RLMotor_Speed(80);
	RRMotor_Speed(-80);
}
void Car_Stop(){
	FLMotor_Speed(0);
	FRMotor_Speed(0);
	RLMotor_Speed(0);
	RRMotor_Speed(0);
}
void Slide_Right(){
	FLMotor_Speed(80);
	FRMotor_Speed(-80);
	RLMotor_Speed(-80);
	RRMotor_Speed(80);
}
void Slide_Left(){
	FLMotor_Speed(-80);
	FRMotor_Speed(80);
	RLMotor_Speed(80);
	RRMotor_Speed(-80);
}	
