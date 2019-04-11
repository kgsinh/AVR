#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
#include<stdio.h>

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
unsigned char i;
cmd(0x80);
for(i=0;z[i]!='\0';i++)
{
dat(z[i]);
}
}

int ADC_R(unsigned char ch)
{
ADMUX=0x40;
ADCSRA=0x86;
ADMUX|=ch;
ADCSRA|=(1<<ADSC);
while((ADCSRA&(1<<ADIF))==0);
return ADC;
}

void main()
{
int x,y,v;
char z[20];

DDRB=0xff;
DDRD=0xff;

cmd(0x01);
cmd(0x06);
cmd(0x0c);
cmd(0x38);
cmd(0x80);

ADMUX=0x40;
ADCSRA=0x86;

while(1)
{
x=ADC_R(0)/2;
y=ADC_R(1)/2;
v=x-y;
sprintf(z,"Temp=%3d%cC",v,0xdf);
display(z);
}
}
