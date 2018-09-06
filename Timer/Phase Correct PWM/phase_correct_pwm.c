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
	TCCR1A = 0b10000010 ; // it is set on Mode 0 Mode 1 change it to  Mode 2(toggle if W13:10 is 9 or 14) 10(Upcounter 0, downcounter 1) Mode 3 11 (upcouunter 1 downcounter 0)
 	TCCR1B = 0b00010001 ;
	TIMSK = 0x04 ;
	
	ICR1  = 999 ;
	OCR1A = 199 ; //on 1000 match on counter 
	

    while(1)
    {
        //TODO:: Please write your application code 
    }
}