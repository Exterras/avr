/*
 * LED_004.c
 *
 * Created: 2016-11-22 오후 10:55:32
 * Author : Exterra
 */ 

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{

	DDRD = 0xFF; // D0 ~ D7까지 출력핀으로 설정
	char patterns[] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
		
    /* Replace with your application code */
    while (1) 
    {	
		for (int i=0; i<sizeof(patterns); i++) {
			PORTD = patterns[i];
			_delay_ms(1000);
		}
    }

	return 1;
}

