#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>

void main()
{
unsigned char i,x[]={0x01,0x02,0x04,0x08};

DDRB=0xff;

while(1)
{
for(i=0;i<=3;i++)
{
PORTB=x[i];
_delay_ms(1000);
}
}
}
