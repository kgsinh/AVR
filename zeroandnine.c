#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>

void display(unsigned char y)
{
unsigned char x[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f};
PORTB=x[y];
}

void main()
{
int i,j,a,b,c,d,q,w,x,y,z;

DDRB=0xff;
DDRD=0xff;

while(1)
{
for(i=0;i<=999;i++)
{
a=i%10;
d=i/10;
b=d%10;
c=d/10;

q=999-i;
w=q%10;
z=q/10;
x=z%10;
y=z/10;

for(j=1;j<=5;j++)
{
PORTD=0x3e;
display(a);
_delay_ms(9);

PORTD=0x3d;
display(b);
_delay_ms(9);

PORTD=0x3b;
display(c);
_delay_ms(9);

PORTD=0x37;
display(w);
_delay_ms(9);

PORTD=0x2f;
display(x);
_delay_ms(9);

PORTD=0x1f;
display(y);
_delay_ms(9);
}
}
}
}
