/*
 * LED_003.c
 *
 * Created: 2016-11-22 오후 8:42:10
 * Author : Exterra
 */ 

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{

	DDRD = 0xFF;

    /* Replace with your application code */
    while (1) 
    {
		PORTD = 0x80;
		_delay_ms(1000); // 1번 패턴
		PORTD = 0x40;
		_delay_ms(1000); // 2번 패턴
		PORTD = 0x20;
		_delay_ms(1000); // 3번 패턴 
		PORTD = 0x10;
		_delay_ms(1000); // 4번 패턴
		PORTD = 0x08;
		_delay_ms(1000); // 5번 패턴
		PORTD = 0x04;
		_delay_ms(1000); // 6번 패턴
		PORTD = 0x02;
		_delay_ms(1000); // 7번 패턴
		PORTD = 0x01;
		_delay_ms(1000); // 8번 패턴

    }
	return 1;
}

