#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>

void maxx(char add,char dat)
{
PORTD&=~(1<<0);
SPDR=add;
while((SPSR&(1<<SPIF))==0);
SPDR=dat;
while((SPSR&(1<<SPIF))==0);
PORTD|=(1<<0);
}

void main()
{
int j=0,q,k,r;

DDRB=(1<<3)|(1<<5);
DDRD=(1<<0);
SPCR=(1<<SPE)|(1<<MSTR)|(1<<SPR0);

maxx(0x09,0x0F);
maxx(0x0A,0x0F);
maxx(0x0B,0x01);
maxx(0x0C,0x00);

while(1)
{
if((PIND&0x02)==0)
{
maxx(0x0C,0x01);
maxx(0x01,j);
_delay_ms(500);
j++;
if(j==10)
{
j=0;
}
}
else if((PIND&0x04)==0)
{
maxx(0x0C,0x01);
q=j-2;
maxx(0x01,q);
_delay_ms(500);
j--;
if(j==0)
{
maxx(0x0C,0x00);
}
}
}
}
