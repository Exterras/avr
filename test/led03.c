#include <avr/io.h>
#include <util/delay.h>

void main(void){

	unsigned char pattern_table[2] = {0x5A, 0xA5};
	
	PORTE = 0xFF;
	DDRE = 0xFF;
	
	while(1){
		PORTE = pattern_table[0];
		_delay_ms(100);

		PORTE = pattern_table[1];
		_delay_ms(100);
	}
}
