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

uint16_t period ;

ISR(TIMER1_CAPT_vect){
	period = ICR1 ;
	TCNT1 = 0 ;
	PORTB = ~PORTB ;
}
void timer_init(){
	TCCR1A = 0x00 ;//normal mode
	TCCR1B = 0xC1 ;//prescaler = 1,8,64,256,1024 
	TIMSK = 0x20 ;//enable overflow interrupt
}

int main(void)
{
	DDRB = 0xFF ;
	timer_init() ;
	PORTB = 0xFF ;
	sei() ;

    while(1)
    {
        //TODO:: Please write your application code 
    }
}