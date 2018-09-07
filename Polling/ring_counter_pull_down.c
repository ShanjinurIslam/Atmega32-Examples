/*
 * RingCounter.c
 *
 * Created: 7/9/18 11:41:40 AM
 *  Author: spondon
 */ 

#define F_CPU 10000000
#include <avr/io.h>
#include <util/delay.h>

int count = 0 ;

int main(void)
{
	DDRA = 0x00 ;
	DDRD = 0xFF ;
	PORTD = 0x00 ;
    while(1)
    {
		if(PINA & (0x01)){
			count++ ;
			PORTD = count & 0xFF ;
			_delay_ms(100) ;
		}
		if(PINA & (0x02)){
			count-- ;
			PORTD = count & 0xFF ;
			_delay_ms(100) ;
		}
		if(PINA & (0x04)){
			PORTD = 0x00 ;
			_delay_ms(100) ;
		}
		
		
        //TODO:: Please write your application code 
    }
}