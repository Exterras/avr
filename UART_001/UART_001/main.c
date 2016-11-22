/*
 * UART_001.c
 *
 * Created: 2016-11-23 오전 1:00:26
 * Author : Exterra
 */ 

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

void UART_INIT(void){
	UCSR0A |= _BV(U2X0); // 2배속 모드
	
	// 통신 속도(보율) 설정
	UBRR0H = 0x00;
	UBRR0L = 207;

	// 비동기, 8비트 데이터, 패리티 없음, 1비트 정지 비트 모드
	UCSR0C |= 0x06;

	UCSR0B |= _BV(RXEN0);
	UCSR0B |= _BV(TXEN0);	 
}

unsigned char UART_receive(void){
	while( !(UCSR0A & (1<<RXC0)) ); // 데이터 수신 대기
	return UDR0;
}

void UART_transmit(unsigned char data){
	while( !(UCSR0A & (1<<UDRE0)) ); // 송신 가능 대기
	UDR0 = data; // 데이터 전송
}

int main(int argc, char *argv[])
{
    unsigned char data;

	UART_INIT(); //  UART 통신 초기화
    while (1) 
    {
		data = UART_receive(); // 데이터 수신
		UART_transmit(data); // 수신된 문자를 에코 백
    }

	return 0;
}

