#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>

void main()
{
DDRB=(1<<4);
DDRD=0xff;
SPCR=(1<<SPE)|(1<<SPR0);
while((SPSR&(1<<SPIF))==0);
PORTD=SPDR;
}

