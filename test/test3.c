#include <avr/io.h>

int main(void){

	PORTE = 0x01;
	DDRE = 0x01;

	while(1){

		if(PINE & 0x80){
			PORTE &= 0xFE;			
		} else {
			PORTE |= 0x01;			
		}
	}

	return 0;

}
