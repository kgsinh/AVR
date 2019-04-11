#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>

void trans(unsigned char z[])
{
unsigned char i;
for(i=0;z[i]!='\0';i++)
{
while((UCSRA&(1<<UDRE))==0);
UDR=z[i];
}
}

void main()
{
unsigned char y;

UBRRL=51;
UCSRB=(1<<TXEN)|(1<<RXEN);
UCSRC=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);

while(1)
{
while((UCSRA&(1<<RXC))==0);
y=UDR;


if(y=='A')
{
trans("B");
}

if(y=='C')
{
trans("D");
}

if(y=='E')
{
trans("F");
}

}
}
