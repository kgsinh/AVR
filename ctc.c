#define F_CPU 8000000UL
#include<avr/io.h>

void main()
{
DDRB=0xff;
TCCR2=0x1A;
OCR2=200;
}
