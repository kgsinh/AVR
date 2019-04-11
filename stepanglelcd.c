#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
#include<stdlib.h>

void cmd(unsigned char y)
{
PORTB=y;
PORTC&=~((1<<0)|(1<<1));
PORTC|=(1<<1);
_delay_ms(10);
PORTC&=~(1<<1);
}

void dat(unsigned char y)
{
PORTB=y;
PORTC&=~((1<<0)|(1<<1));
PORTC|=(1<<0);
PORTC|=(1<<1);
_delay_ms(10);
PORTC&=~(1<<1);
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
unsigned char i,x[]={0x01,0x02,0x04,0x08},z[20],j=0;
float k;

DDRB=0xff;
DDRC=0xff;
DDRD=0xff;

cmd(0x01);
cmd(0x06);
cmd(0x0c);
cmd(0x38);
cmd(0x80);

for(i=0;i<=50;i++)
{
PORTD=x[j];
_delay_ms(1000);
j++;

float k=1.8*i;
dtostrf(k,0,3,z);
cmd(0x80);
display("Angle=");
cmd(0x86);
display(z);

if(j==4)
{
j=0;
}

}
}
