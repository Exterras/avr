/*
 * LED_RGB002.c
 *
 * Created: 2016-11-22 오후 7:28:22
 * Author : Exterra
 */ 
#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

int switchCon;
char key_in;

void switchOn(){
	if (switchCon == 0) {
		if (PORTD == 0x04) {
			PORTB = 0x0E;
		} else if (PORTD == 0x08){
			PORTB = 0x0D;
		} else if (PORTD == 0x10) {
			PORTB = 0x0B;
		} else if (PORTD == 0x20) {
			PORTB = 0x08;
		}
	} 
	switchCon = 1;
}

void switchOff(){
	if (switchCon == 1) {
		if (PORTD == 0x04 || PORTD == 0x08 || PORTD == 0x10 || PORTD == 0x20) {
			PORTB = 0x00;
		}
	}
	switchCon = 0;
}

int main(void) {
	DDRD = 0xC3; // 입력
	DDRB = 0x0F; // 출력

	key_in = PIND & 0x01;

	if (key_in == 0) {
		PORTB = 0x0E;
		_delay_ms(1000);
		PORTB = 0x0D;
		_delay_ms(1000);
		PORTB = 0x0B;
		_delay_ms(1000);
	} else {
		PORTB = 0x00;
	}
	
	return 0;		
}



