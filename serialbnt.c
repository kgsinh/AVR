#define F_CPU 80000000UL
#include<avr/io.h>
#include<util/delay.h>
#include<string.h>

void main()
{
unsigned char x[10],i=0;

DDRB=0xff;

UBRRL=51;
UCSRB=(1<<RXEN);
UCSRC=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);

while(1)
{
do
{
if(strncmp(x,"blink",5)==0)
{
PORTB=0x00;
_delay_ms(150);
PORTB=0xff;
_delay_ms(150);
i=0;
}

if(strncmp(x,"toggle",6)==0)
{
PORTB=0x55;
_delay_ms(150);
PORTB=0xaa;
_delay_ms(150);
i=0;
}
}while((UCSRA&(1<<RXC))==0);
x[i]=UDR;
i++;
}
}

