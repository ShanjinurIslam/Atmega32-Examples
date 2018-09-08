/*
 * ADC.c
 *
 * Created: 7/9/18 12:32:48 PM
 *  Author: spondon
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
volatile int result ;

void ADC_init(){
	ADMUX  = 0b01100000 ; //left justified
	ADCSRA = 0b10000001 ;
}

ISR(ADC_vect){
	int a = ADCL ;
	int b = ADCH ;
	result = ((b<<2) | (a>>6)) ;
}

int main(void)
{
	ADC_init() ;
	float step = 5.0/1024 ;
	ADCSRA |= (1<<ADSC) ; 
	sei() ;

	//get_voltage
	float vol = step*result ; //use lcd.h to show the output value
	
    while(1)
    {
        //TODO:: Please write your application code 
    }
}
