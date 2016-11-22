/*
 * LED_006.c
 *
 * Created: 2016-11-23 오전 12:17:33
 * Author : Exterra
 */ 

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD = 0xFF; // D0 ~ D7까지 출력핀으로 설정

    /* Replace with your application code */
    while (1) 
    {
		for (int i = 0; i < 8; i++)
		{	
			char p1 = 0x01 << i;
			char p2 = 0x01 << (7-i);
			PORTD = p1 | p2;
			_delay_ms(1000);
		}
    }

	return 1;
}

