#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
#define led PORTB

void main()
{
DDRB=0xef;

while(1)
{
if((PINB&0x10)==0x10)
{
led&=0x7e;
led|=0x81;
_delay_ms(100);
led=0x7e;
_delay_ms(100);
}
else
{
led=0x7e;
}
}
}
