/*
 * UART.h
 *
 * Created: 2016-11-23 오후 6:47:39
 *  Author: Exterra
 */ 


#ifndef UART_H_
#define UART_H_
#include <avr/io.h>

void UART_INIT(void); // UART 초기화
unsigned char UART_receive(void); // 1바이트 수신
void UART_transmit(unsigned char data); // 1바이트 송신
void UART_printString(char *str); // 문자열 송신

void UART_print8bitNumber(uint8_t no); 
void UART_print16bitNumber(uint16_t no);
void UART_print32bitNumber(uint32_t no);
// 숫자를 문자열로 변환하여 송신

#endif /* UART_H_ */