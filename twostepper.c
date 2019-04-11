#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>

void main()
{
unsigned char i,x[]={0x81,0x42,0x24,0x18},j=0;

DDRB=0xff;


for(i=0;i<=49;i++)
{
PORTB=x[j];
_delay_ms(1000);
j++;
if(j==4)
{
j=0;
}
}
}
