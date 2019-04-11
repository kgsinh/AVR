#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>

void main()
{
DDRD=0xf7;

if((PIND&~(1<<3))==0)
{

PORTD&=~((1<<4)|(1<<7));
PORTD|=(1<<4)|(1<<7);
_delay_ms(300);
PORTD&=~((1<<4)|(1<<7));
_delay_ms(300);

}

else
{
PORTD&=~((1<<4)|(1<<7));
}
}
