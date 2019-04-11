#define F_CPU 8000000UL
#include<avr/io.h>

void delay()
{
TCCR1A=0x00;
TCCR1B=0x02;
TCNT1H=15536;
while((TIFR&(1<<TOV1))==0);
TIFR=(1<<TOV1);
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
