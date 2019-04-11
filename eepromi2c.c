#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>

void start_i2c()
{
TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
while((TWCR&(1<<TWINT))==0);
}

void wr_i2c(unsigned char dat)
{
TWDR=dat;
TWCR=(1<<TWINT)|(1<<TWEN);
while((TWCR&(1<<TWINT))==0);
}

void stop_i2c()
{
TWCR=(1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
while((TWCR&(1<<TWINT))==0x10);
}

void main()
{
TWBR=8;

start_i2c();
wr_i2c(0xA0);
wr_i2c(0x1D);
wr_i2c(0x55);
stop_i2c();
}
