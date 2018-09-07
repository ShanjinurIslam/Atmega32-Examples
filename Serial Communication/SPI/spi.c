#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>

void SPI_master_init()
{
	DDRB = (1<<DDB5)|(1<<DDB7) ;
	SPCR = (1<<SPE) | (1<<MSTR) | (1<<SPR0) ;
}

void SPI_slave_init(){
	DDRB = 1<<DDB6 ;
	SPCR = (1<<SPE) ;
}

void transmit(char data){
	SPDR = data ;
	while(!(SPSR & (1<<SPIF))) ;
}

char data_receive(){
	while(!(SPSR & (1<<SPIF))) ;
	return SPDR ;
}


int main()
{
	SPI_slave_init() ;
	DDRD = 0xFF ;
	PORTD = 0x00 ;
	while(1){
		char data = data_receive() ;
		if(data){
			PORTD = ~PORTD ;
			_delay_ms(100) ;
			PORTD = ~PORTD ;
			_delay_ms(100) ;
		}
		
	}
	return 0 ;
}
