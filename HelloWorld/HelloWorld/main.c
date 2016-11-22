/*
 * HelloWorld.c
 *
 * Created: 2016-11-20 오후 5:37:00
 * Author : Exterra
 */ 

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB = 0x20;

    /* Replace with your application code */
    while (1) 
    {
		PORTB = 0x00;
		_delay_ms(2000);
		PORTB = 0x20;
		_delay_ms(2000);
    }

	return 1;
}

