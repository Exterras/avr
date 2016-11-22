#include <avr/io.h>

int main(void){
	unsigned char input_value;
	unsigned char output_value;

	PORTE = 0x01;
	DDRE = 0x01;

	output_value = 0x01;

	while(1){
		input_value = PINE & 0x80;
		
		if(input_value){
			PORTE &= ~output_value;			
		} else {
			PORTE |= output_value;			
		}
	}

	return 0;

}
