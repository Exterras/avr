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
	// UCSR0A 레지스터는 UART 통신의 제어와 상태를 알아보기 위한 레지스터 중 하나이다.
	// 여기서는 2배속 설정과 송신 및 수신이 가능한지 여부를 판단하기 위한 목적으로 사용되었다.
	// 2배속 설정을 위해서는 UCSR0A 레지스터의 1번비트인 'U2X0' 비트를 1로 설정해주면 된다.
	// _BV는 지정한 비트만을 1로 하고 나머지를 0으로 하는 비트 마스크를 생성하는 매크로이다.

	// 통신 속도(보율) 설정
	UBRR0H = 0x00;
	UBRR0L = 207; //BAUD가 9600 일때 2배속(U2X0 = 1)일때의 값

	// 비동기, 8비트 데이터, 패리티 없음, 1비트 정지 비트 모드
	UCSR0C |= 0x06;  

	UCSR0B |= _BV(RXEN0); // 수신기 수신기능 활성화
	UCSR0B |= _BV(TXEN0); // 송신기 송신기능 활성화
	// UCSR0B 레지스터는 데이터 송수신을 가능하도록 설정하기 위해 사용되었다.
	// 디폴트값으로는 UART 통신의 송수신이 금지되어있다.	 
}

unsigned char UART_receive(void){
	while( !(UCSR0A & (1<<RXC0)) ); // 데이터 수신 대기
	// UCSR0A 레지스터의 중요한 기능 중 하나는 데이터를 수신하거나 송신할 준비가 되어 있는지를 확인하는 기능으로
	// 이를 위해 7번 RXC0 비트와 5번 UDRE0 비트를 사용한다.
	// RXC0 비트는 데이터 수신 버퍼에 데이터가 도착하고 읽지 않은 상태인 경우 1로 설정되므로
	// 데이터가 수신되었는 지 여부를 판단하기 위해 사용할 수 있다.
	// 여기서는 데이터가 수신될 때까지 기다리기 위해, RXC0 비트가 1이 될때까지 기다리기 위해 while 문장을 사용하고 있다.

	return UDR0;
}

void UART_transmit(unsigned char data){
	while( !(UCSR0A & (1<<UDRE0)) ); // 송신 가능 대기
	// 위의 UART_receive()와 유사하게 데이터가 완전히 전송되고 다음 데이터를 전송할 준비가 되어있는지
	// 확인하기 위해 UDRE0 비트를 사용할 수 있다.
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

