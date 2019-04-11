#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>

void cmd(unsigned char y)
{
PORTB=y;
PORTC=0x02;
_delay_ms(10);
PORTC=0x00;
}

void dat(unsigned char y)
{
PORTB=y;
PORTC=0x03;
_delay_ms(10);
PORTC=0x01;
}

void display(unsigned char z[])
{
unsigned char i;
cmd(0x80);
for(i=0;z[i]!='\0';i++)
{
dat(z[i]);
}
}

void main()
{
int x;
char z[20];

DDRB=0xff;
DDRC=0xff;

cmd(0x01);
cmd(0x06);
cmd(0x0c);
cmd(0x38);
cmd(0x80);

TCCR0=0x06;
TCNT0=0;

while(1)
{
do
{
x=TCNT0;
sprintf(z,"Count=%3d",x);
display(z);
}while((TIFR&(1<<TOV0))==0);
TIFR=(1<<TOV0);
}
}
