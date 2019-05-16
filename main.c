/*
 * GccApplication2.c
 *
 * Created: 16-May-19 12:39:40 PM
 * Author : JAYASREE
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/io.h>
#include <inttypes.h>
#include <avr/interrupt.h>
#define LED PORTB
char buffer[10];
void USARTInit(uint16_t ubrr_value)
{
	//set baud rate
	UBRRL=ubrr_value;
	UBRRH=(ubrr_value>>8);
	UCSRC=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	//Enable the RECEIVER & TRANSMITTER
	UCSRB=(1<<RXEN)|(1<<TXEN);
}
char USARTReadChar()
{
	
	//Wait until a data is available
	while(!(UCSRA&(1<<RXC)))
	{
		
		//Do nothing
	}
	return UDR;
	
}
void USARTWriteChar(char data)
{
	while(!(UCSRA&(1<<UDRE)))
	{
		//Do nothing
	}
	UDR=data;
}
 
 int main(void)
{
	
	USARTInit(77);
	DDRB=0XFF;//PORTB as o/p
	char data;
	
  /* Replace with your application code */
    while (1) 
    {
		data=USARTReadChar();
		if(data=='1')
		{
			PORTB=1<<PB0;
		}
		else if(data=='2')
		{
			
			PORTB=0<<PB0;
		}

		else if(data=='3')
		{
			PORTB=1<<PB1;
		}
		else if (data=='4')
		{
			PORTB=0<<PB1;
		}
	}
	return(0);
    
}

