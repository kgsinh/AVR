#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>

void maxx(char ad, char dat)
{
PORTD&=~(1<<0);
SPDR=ad;
while((SPSR&(1<<SPIF))==0);
SPDR=dat;
while((SPSR&(1<<SPIF))==0);
PORTD|=(1<<0);
}

void main()
{
int i,j,k;

DDRB=(1<<3)|(1<<5);
DDRD=(1<<0);

SPCR=(1<<SPE)|(1<<MSTR)|(1<<SPR0);

maxx(0x09,0x0F);
maxx(0x0A,0x0F);
maxx(0x0B,0x03);
maxx(0x0C,0x01);

for(k=0;k<10;k++)
{
maxx(0x03,k);
for(j=0;j<10;j++)
{
maxx(0x02,j);
for(i=0;i<10;i++)
{
maxx(0x01,i);
_delay_ms(500);
}
}
}
}


