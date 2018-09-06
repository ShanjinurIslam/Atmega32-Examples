/*
 * GccApplication1.c
 *
 * Created: 5/9/18 10:22:24 PM
 *  Author: spondon
 */ 


//create accurate 2s time delay no prescaler
#define F_CPU 1000000
#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
	DDRB = 0xFF ; 
	DDRD = 0xFF ;
	PORTB = 0xFF ;
	TCCR1A = 0b10100010 ; // it is set on Mode 0 Mode 1 change it to  Mode 2(toggle) 10(set output on high) Mode 3 11 (Set output on inverting mode)
 	TCCR1B = 0b00011001 ;
	TIMSK = 0x04 ;

	ICR1  = 0x1F3F ;
	OCR1A = 0x95F  ;  //on 1000 match on counter 
	OCR1B = 0x12BF ;

    while(1)
    {
        //TODO:: Please write your application code 
    }
}