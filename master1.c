#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>

void main()
{
DDRB=(1<<2)|(1<<3)|(1<<5);
DDRD=0xff;
SPCR=(1<<SPE)|(1<<MSTR)|(1<<SPR0);

PORTD=0x02;
SPDR=0x55;
while((SPSR&(1<<SPIF))==0);

PORTD=0x01;
SPDR=0xaa;
while((SPSR&(1<<SPIF))==0);
}

