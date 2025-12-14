#ifndef __SERIALA_H
#define __SERIALA_H

#include <stdio.h>

extern char SerialA_RxPacket[];
extern uint8_t SerialA_RxFlag;

void SerialA_Init(void);
void SerialA_SendByte(uint8_t Byte);
void SerialA_SendArray(uint8_t *Array, uint16_t Length);
void SerialA_SendString(char *String);
void SerialA_SendNumber(uint32_t Number, uint8_t Length);
void SerialA_Printf(char *format, ...);

#endif
