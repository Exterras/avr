/*
 * GccApplication1.c
 *
 * Created: 2016-11-17 오전 12:17:07
 * Author : Exterra
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main() {
	// 셋업
	DDRB = 0xFF;

	while (1) {
		PORTB = 0xFF;
		_delay_loop_2(1000);
		PORTB = 0x00;
		_delay_loop_2(1000);
	}
}