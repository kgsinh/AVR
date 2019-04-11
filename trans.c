#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>

void trans(unsigned char z[])
{
unsigned int i;
for(i=0;z[i]!='\0';i++)
{
while((UCSRA&(1<<UDRE))==0);
UDR=z[i];
}
}

void main()
{

UBRRL=51;
UCSRB=(1<<TXEN)|(1<<RXEN);
UCSRC=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);

trans("HELLO");




}
