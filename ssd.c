#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>

void main()
{
char i,x[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f};

DDRB=0xff;

while(1)
{
for(i=0;i<=9;i++)
{
PORTB=x[i];
_delay_ms(500);
}
}
}
