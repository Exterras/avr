#include <avr/io.h>

int main(void){
	unsigned char input_value;
	PORTE = 0x01;
	DDRE = 0x01;

	while(1){
		input_value = PINE & 0x80;
		
		if(input_value == 0x80){
			PORTE |= 0x01;			
		} else {
			PORTE |= 0xFE;			
		}
	}

	return 0;

}
