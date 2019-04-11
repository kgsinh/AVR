#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
#define led PORTB

void main()
{
int i;
DDRB=0xff;

while(1)
{
for(i=0;i<=255;i++)
{
led=0x01*i;
_delay_ms(100);
i*=2;
}
}
}
