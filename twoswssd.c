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
int i=0,j=0,p,q;

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
maxx(0x02,j);
maxx(0x01,i);
_delay_ms(500);
i++;
if(i==10)
{
i=0;
j++;
}
}


else if((PIND&0x04)==0)
{
q=j;
p=i-1;
maxx(0x0C,0x01);
maxx(0x02,q);
maxx(0x01,p);
_delay_ms(500);
i--;
if(i==0)
{
i=10;
j--;
}
}

}
}
