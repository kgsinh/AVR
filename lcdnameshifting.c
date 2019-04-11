#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>

void cmd(unsigned char y)
{
PORTB=y;
PORTC&=~(1<<0);
PORTD&=~(1<<3);
PORTD|=(1<<3);
_delay_ms(10);
PORTD&=~(1<<3);
}

void dat(unsigned char y)
{
PORTB=y;
PORTC&=~(1<<0);
PORTD&=~(1<<3);
PORTC|=(1<<3);
PORTD|=(1<<3);
_delay_ms(10);
PORTD&=~(1<<3);
}

void display(unsigned char z[])
{
unsigned char i;
for(i=0;z[i]!='\0';i++)
{
dat(z[i]);
}
}

void main()
{

DDRB=0xff;
DDRC=0xff;
DDRD=0xff;

cmd(0x01);
cmd(0x06);
cmd(0x0c);
cmd(0x38);
cmd(0x80);

display("Hello");
}

 
