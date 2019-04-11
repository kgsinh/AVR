#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
#include<stdio.h>

void cmd(unsigned char y)
{
PORTB=y;
PORTD&=0xf6;
PORTD|=0x08;
_delay_ms(10);
PORTD&=0xf6;
}

void dat(unsigned char y)
{
PORTB=y;
PORTD&=0xf6;
PORTD|=0x09;
_delay_ms(10);
PORTD&=0xf7;
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
unsigned char i,z[10];

DDRB=0xff;
DDRD=0xff;

cmd(0x01);
cmd(0x06);
cmd(0x0c);
cmd(0x38);
cmd(0x80);

while(1)
{
for(i=0;i<=99;i++)
{
sprintf(z,"%2d",i);
display(z);
_delay_ms(200);
}
}
}
