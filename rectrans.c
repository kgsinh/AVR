#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>


void main()
{
unsigned char y;
DDRB=0xff;

UBRRL=51;
UCSRB=(1<<RXEN);
UCSRC=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);

while(1)
{
while((UCSRA&(1<<RXC))==0);
y=UDR;

if(y=='A')
{
PORTB=0x01;
}

else if(y=='B')
{
PORTB=0x02;
}

else
{
PORTB=0x00;
}
}
}
