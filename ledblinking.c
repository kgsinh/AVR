#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>

void main()
{
DDRB=0xff;

while(1)
{
PORTB=0xff;
_delay_ms(100);
PORTB=0x00;
_delay_ms(100);
}
}
