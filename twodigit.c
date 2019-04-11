#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>

void display(unsigned char y)
{
char x[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f};
PORTB=x[y];
}

void main()
{
int i=12,a,b;

DDRB=0xff;
DDRD=0xff;
while(1)
{
a=i%10;
b=i/10;
PORTD=0x02;
display(a);
_delay_ms(45);
PORTD=0x01;
display(b);
_delay_ms(45);
}
}

