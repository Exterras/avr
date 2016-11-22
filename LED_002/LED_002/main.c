/*
 * LED_002.c
 *
 * Created: 2016-11-22 오후 8:36:00
 * Author : Exterra
 */ 
#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD = 0xFF;
	// 포트 D0 ~ D7까지 8개의 핀을 출력으로 설정

    /* Replace with your application code */
    while (1) 
    {
		PORTD = 0x55;
		// 홀수번째 LED 켜기
		_delay_ms(1000);
		
		PORTD = 0xAA;
		// 짝수번째 LED 켜기
		_delay_ms(1000);

    }

	return 1;
}

