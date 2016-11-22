/*
 * LED_RGB01.c
 *
 * Created: 2016-11-22 오후 5:41:35
 * Author : Exterra
 */ 
#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRD = 0xFF;
	// D0 ~ D7 pin 출력, (모든 핀을 출력하려면 비트 1로 만들기)
	// 반대로 모두 입력을 하려면 모든 비트를 0 으로 만들기 

    /* Replace with your application code */
    while (1) 
    {
		PORTD = 0xEF;
		_delay_ms(1000);
		PORTD = 0xF7;
		_delay_ms(1000);
		PORTD = 0xFB;
		_delay_ms(1000);
    }
}

