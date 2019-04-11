#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>

void main()
{
DDRB=(1<<2)|(1<<3)|(1<<5);
SPCR=(1<<SPE)|(1<<MSTR)|(1<<SPR0);
SPDR=0x55;
while((SPSR&(1<<SPIF))==0);
}

