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

ISR(TIMER1_COMPA_vect){
	PORTB = ~PORTB ;
}

int main(void)
{
	DDRB = 0xFF ; 
	DDRD = 0xFF ;
	PORTB = 0xFF ;
	TCCR1A = 0b01000000; // it is set on Mode 0 Mode 1 change it to  Mode 2(toggle) 10(set output on high) Mode 3 11 (Set output on inverting mode)
 	TCCR1B = 0b00001001 ;
	TIMSK = 0x10 ;
	
	OCR1A = 1000 ; //on 1000 match on counter 
	sei() ;

    while(1)
    {
        //TODO:: Please write your application code 
    }
}