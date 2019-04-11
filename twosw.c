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
int j,k,q,r;

DDRB=(1<<3)|(1<<5);
DDRD=(1<<0);
SPCR=(1<<SPE)|(1<<MSTR)|(1<<SPR0);

maxx(0x09,0x0F);
maxx(0x0A,0x0F);
maxx(0x0B,0x01);
maxx(0x0C,0x01);

while(1)
{
if((PIND&0x02)==0)
{
maxx(0x0C,0x01);
for(k=0;k<=9;k++)
{
maxx(0x02,k);
for(j=0;j<=9;j++)
{
maxx(0x01,j);
_delay_ms(500);

if((PIND&0x04)==0)
{
maxx(0x0C,0x01);
for(r=k;r>=0;r--)
{
maxx(0x02,r);

for(q=j;q>=0;q--)
{
maxx(0x01,q);
_delay_ms(500);
}
j=9;
}
maxx(0x0C,0x00);
}
}
}
}

else
{
maxx(0x0C,0x00);
}
}
}
