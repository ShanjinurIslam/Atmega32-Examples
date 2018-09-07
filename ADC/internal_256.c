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
	ADMUX  = 0b11100000 ; //internal 2.56V left justified
	ADCSRA = 0b10000001 ;
}

ISR(ADC_vect){
	int a = ADCH ;
	result = a ;
}

int main(void)
{
	ADC_init() ;
	float step = 2.56/1024 ;
	ADCSRA |= (1<<ADSC) ;
	sei() ;

	//get_voltage
	float vol = step*result ; //use lcd.h to show the output value
	
    while(1)
    {
        //TODO:: Please write your application code 
    }
}