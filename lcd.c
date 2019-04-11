#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>

void cmd(unsigned char y)
{
PORTB=y;
PORTD=0x02;
_delay_ms(10);
PORTD=0x00;
}

void dat(unsigned char y)
{
PORTB=y;
PORTD=0x03;
_delay_ms(10);
PORTD=0x01;
}

void display(unsigned char z[])
{
unsigned int i;
for(i=0;z[i]!='\0';i++)
{
dat(z[i]);
}
}

void main()
{
DDRB=0xff;
DDRD=0xff;

cmd(0x01);
cmd(0x06);
cmd(0x0c);
cmd(0x38);
cmd(0x80);
display("HELLO");
} 
