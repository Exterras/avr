/*
 * UART_002.c
 *
 * Created: 2016-11-23 오후 6:47:02
 * Author : Exterra
 */ 

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include "UART.h" // 사용자 라이브러리 UART.h 사용
// 라이브러리는 xxx.h (헤더파일)과 xxx.c(소스파일)로 나눠져 있다. 

int main(void)
{
    unsigned char data;
	UART_INIT(); // UART 통신 초기화

    while (1) 
    {
		data = UART_receive(); // 데이터 수신
		UART_transmit(data);	// 수신된 문자를 에코 백
    }
	return 0;
}

