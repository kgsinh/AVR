#define F_CPU 8000000UL
#include<avr/io.h>

void main()
{
DDRB=0xff;
TCCR1A=0x22;
TCCR1B=0x02;
TCNT1=0;
OCR1B=125;
}
