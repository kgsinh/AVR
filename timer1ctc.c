#define F_CPU 8000000UL
#include<avr/io.h>

void main()
{
DDRB=0xff;
TCCR1A=0x40;
TCCR1B=0x0A;
TCNT1=0;
OCR1A=60000;
}
