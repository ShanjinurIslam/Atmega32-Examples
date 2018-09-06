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
	DDRD = 0xFF ;
	TCCR1A = 0b10000000 ; // Mode 0 Mode 1 change it to 01XXXXXX Mode 2(toggle) 10(set output on high) Mode 3 11 (Set output on low)
 	TCCR1B = 0b00001001 ;
	TIMSK = 0x04 ;
	
	OCR1A = 1000 ; //on 1000 match on counter 

    while(1)
    {
        //TODO:: Please write your application code 
    }
}