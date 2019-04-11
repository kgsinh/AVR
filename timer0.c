#define F_CPU 8000000UL
#include<avr/io.h>

void delay()
{
TCCR0=0x02;
TCNT0=56; //finalcount//
while((TIFR&(1<<TOV0))==0);
TIFR=(1<<TOV0);
}

void main()
{
DDRB=0xff;

while(1)
{
PORTB=0xff;
delay();
PORTB=0x00;
delay();
}
}
