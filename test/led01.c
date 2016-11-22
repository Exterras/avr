#include <avr/io.h>
#include <util/delay.h>

void main(void){
	PORTE = 0xFF;
	DDRE = 0xFF;

	while(1){
		PORTE = 0x5A;
		_delay_ms(100);
		PORTE = 0xA5;
		_delay_ms(100);
	}
}
