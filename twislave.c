#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>

void i2c_wait()
{
TWCR=(1<<TWINT)|(1<<TWEA)|(1<<TWEN);
while((TWCR&(1<<TWINT))==0);
}

int i2c_rd()
{
TWCR=(1<<TWINT)|(1<<TWEN);
while((TWCR&(1<<TWINT))==0);
return TWDR;
}

void main()
{
DDRD=0xff;
TWAR=0x02;
i2c_wait();
PORTD=i2c_rd();
}
