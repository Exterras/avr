/*
 * UART.c
 *
 * Created: 2016-11-23 오후 6:47:21
 *  Author: Exterra
 */
 
 #include "UART.h"
 
 void UART_INIT(void){
	UCSR0A |= _BV(U2X0); // 2배속 모드

	UBRR0H = 0x00;
	UBRR0L = 207; 
	// 통신 속도(보율) 설정

	UCSR0C |= 0x06;
	// 비동기, 8비트 데이터, 패리티 없음, 1비트 정지 비트 모드

	UCSR0B |= _BV(RXEN0); // 수신기 수신기능 활성화
	UCSR0B |= _BV(TXEN0); // 송신기 송신기능 활성화
	// UCSR0B 레지스터는 데이터 송수신을 가능하도록 설정하기 위해 사용되었다.
	// 디폴트값으로는 UART 통신의 송수신이 금지되어있다.
 } 

 unsigned char UART_receive(void){ // 1바이트 수신
	while( !(UCSR0A & (1<<RXC0)) ); // 데이터 수신 대기
		// UCSR0A 레지스터의 중요한 기능 중 하나는 데이터를 수신하거나 송신할 준비가 되어 있는지를 확인하는 기능으로
		// 이를 위해 7번 RXC0 비트와 5번 UDRE0 비트를 사용한다.
		// RXC0 비트는 데이터 수신 버퍼에 데이터가 도착하고 읽지 않은 상태인 경우 1로 설정되므로
		// 데이터가 수신되었는 지 여부를 판단하기 위해 사용할 수 있다.
		// 여기서는 데이터가 수신될 때까지 기다리기 위해, RXC0 비트가 1이 될때까지 기다리기 위해 while 문장을 사용하고 있다.
	return UDR0;
 }

 void UART_transmit(unsigned char data){ // 1바이트 송신
	while( !(UCSR0A & (1<<UDRE0)) ); // 송신 가능 대기
	// 위의 UART_receive()와 유사하게 데이터가 완전히 전송되고 다음 데이터를 전송할 준비가 되어있는지
	// 확인하기 위해 UDRE0 비트를 사용할 수 있다.
	UDR0 = data; // 데이터 전송
 }

void UART_printString(char *str) { // 문자열 송신
	for (int i=0; str[i];i++) { // str[i] == '\0' 일때까지 반복
		UART_transmit(str[i]); // 바이트 단위 출력
	}
}

void UART_print8bitNumber(uint8_t no){ // 숫자를 문자열로 변환하여 송신, 8비트
	char numString[4] = "0";
	int i, index = 0;

	if (no > 0) {	// 문자열 변환
		for (i=0; no!=0; i++) {
			numString[i] = no % 10 +'0';
			no = no / 10;
		}
		numString[i] = '\0';
		index = i-1;
	}

	for (i=index; i>=0; i--) { // 변환된 문자열 출력
		UART_transmit(numString[i]);
	}
}

void UART_print16bitNumber(uint16_t no){ // 숫자를 문자열로 변환하여 송신, 16비트
	char numString[6] = "0";
	int i, index = 0;

	if (no > 0) {	// 문자열 변환
		for (i=0; no!=0; i++) {
			numString[i] = no % 10 +'0';
			no = no / 10;
		}
		numString[i] = '\0';
		index = i-1;
	}

	for (i=index; i>=0; i--) { // 변환된 문자열 출력
		UART_transmit(numString[i]);
	}
}

void UART_print32bitNumber(uint32_t no){ // 숫자를 문자열로 변환하여 송신, 32비트
	char numString[11] = "0";
	int i, index = 0;

	if (no > 0) {	// 문자열 변환
		for (i=0; no!=0; i++) {
			numString[i] = no % 10 +'0';
			no = no / 10;
		}
		numString[i] = '\0';
		index = i-1;
	}

	for (i=index; i>=0; i--) { // 변환된 문자열 출력
		UART_transmit(numString[i]);
	}
}
