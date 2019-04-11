#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
#define led PORTB

void main()
{
DDRB=0xfe;

while(1)
{
if((PINB&0x01)==0)
{
led&=0xcf;
led|=0x30;
_delay_ms(100);
led&=0xcf;
_delay_ms(100);
}
else
{
led&=0xcf;
}
}
}
