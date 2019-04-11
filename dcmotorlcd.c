#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>


void cmd(unsigned char y)
{
PORTD=y;
PORTB&=~(1<<4);
PORTC&=~(1<<4);
PORTC|=(1<<4);
_delay_ms(10);
PORTC&=~(1<<4);
}

void dat(unsigned char y)
{
PORTD=y;
PORTB&=~(1<<4);
PORTC&=~(1<<4);
PORTB|=(1<<4);
PORTC|=(1<<4);
_delay_ms(10);
PORTC&=~(1<<4);
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
DDRB=0x7e;
DDRD=0xff;
DDRC=0xff;

cmd(0x01);
cmd(0x06);
cmd(0x0c);
cmd(0x38);
cmd(0x80);

while(1)
{
if((PINB&(1<<0))==0x01)
{
PORTB&=~(1<<1);
PORTC&=~(1<<1);
PORTB|=(1<<1);
display("Forward");
}

else if((PINB&(1<<7))==0x80)
{
PORTB&=~(1<<1);
PORTC&=~(1<<1);
PORTC|=(1<<1);
display("Reverse");
}

else
{
PORTB&=~(1<<1);
PORTC&=~(1<<1);
PORTB|=(1<<1);
PORTC|=(1<<1);
display("Stop              ");
}
}
} 
