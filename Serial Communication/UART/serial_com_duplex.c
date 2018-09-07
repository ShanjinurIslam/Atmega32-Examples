/*
 * SerialCom1.c
 *
 * Created: 5/25/2018 11:50:26 AM
 *  Author: Spondon
 */ 

#define F_CPU 1000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


void UART_init(){
	UCSRA = 0x00 ;
	UCSRB = 0x18 ;
	UCSRC = 0x86 ;
	UBRRL = 0x33 ;
	UBRRH = 0x00 ;
}

void UART_send(unsigned char data){
	while((UCSRA & (1<<UDRE))==0x00);
	UDR = data ;
}

unsigned char UART_receive(){
	while(((UCSRA)&(1<<RXC))==0);
	return UDR ;
}

ISR(INT0_vect){
	UART_send('a') ;
	UCSRA = 0x00 ;
	PORTA = 0xFF;
	_delay_ms(100) ;
	PORTA = 0x00 ;
	_delay_ms(100) ;
}
int main(void)
{
	DDRB = 0xFF ;
	DDRA = 0xFF ;
	UART_init() ;
	unsigned char c ;
	MCUCR = (MCUCR | 0x03) ;
	GICR = 0x40 ;
	sei() ;
    while(1)
    {
		c = UART_receive() ;
		if(c=='a'){
			PORTB = 0xFF ;
			_delay_ms(250) ;
			PORTB = 0x00 ;
			_delay_ms(250) ;
		}
    }
}
