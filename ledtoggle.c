#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>

void main()
{
DDRB=0xff;

while(1)
{
PORTB=0x55;
_delay_ms(100);
PORTB=0xaa;
_delay_ms(100);
}
}
