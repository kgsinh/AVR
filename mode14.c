#define F_CPU 8000000UL
#include<avr/io.h>

void main()
{
DDRB=0xff;
TCCR1A=0x82;
TCCR1B=0x1A;
TCNT1=0;
ICR1=2000;
OCR1A=500;
}
