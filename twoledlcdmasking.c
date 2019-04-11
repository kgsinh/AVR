#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>

void cmd(unsigned char y)
{
PORTB=y;
PORTC&=0xef;
PORTD&=0xbf;
PORTD|=0x40;
_delay_ms(10);
PORTD&=0xbf;
}

void dat(unsigned char y)
{
PORTB=y;
PORTC&=0xef;
PORTD&=0xbf;
PORTC|=0x10;
PORTD|=0x40;
_delay_ms(10);
PORTD&=0xbf;
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

DDRB=0xff;
DDRC=0x7b;
DDRD=0xfb;

cmd(0x01);
cmd(0x06);
cmd(0x0c);
cmd(0x38);
cmd(0x80);

while(1)
{

if((PINC&0x04)==0)
{
PORTC&=0xf6;
PORTC|=0x09;
_delay_ms(300);
PORTC&=0xf6;
display("blinking              ");
}

else if((PIND&0x04)==0x04)
{
PORTC&=0xf6;
PORTC|=0x01;
_delay_ms(300);
PORTC&=0xf6;
PORTC|=0x08;
_delay_ms(300);
display("toggle               ");
}

else
{
PORTC&=0xf6;
display("Press any button");
}
}
}
