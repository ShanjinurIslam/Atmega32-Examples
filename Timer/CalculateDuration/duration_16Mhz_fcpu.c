/*
 *
 * Created: 5/9/18 10:22:24 PM
 *  Author: spondon
 */ 


//create accurate 2s time delay no prescaler
#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
volatile int overFlow ;

ISR(TIMER1_OVF_vect){
	overFlow++ ;
}
void timer_init(){
	TCCR1A = 0x00 ;//normal mode
	TCCR1B = 0x02 ;//prescaler = 1,8,64,256,1024 
	TIMSK = 0x04 ;//enable overflow interrupt
}

int main(void)
{
	DDRB = 0xFF ;
	timer_init() ;
	overFlow = 0 ;
	PORTB = 0xFF ;
	sei() ;
	int i = 0 , j = 0 ;
	for(i=0;i<10;i++){
		for(j=0;j<100;j++){
		}
	}
	
	uint32_t elapsed_time = overFlow*65536 +  uint32_t(TCNT1) ;
	cli() ;
	
    while(1)
    {
        //TODO:: Please write your application code 
    }
}