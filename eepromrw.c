#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>

void i2c_start()
{
TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
while((TWCR&(1<<TWINT))==0);
}

void i2c_wr(unsigned char dat)
{
TWDR=dat;
TWCR=(1<<TWINT)|(1<<TWEN);
while((TWCR&(1<<TWINT))==0);
}

int i2c_rd()
{
TWCR=(1<<TWINT)|(1<<TWEN);
while((TWCR&(1<<TWINT))==0);
return TWDR;
}

void i2c_stop()
{
TWCR=(1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
while((TWCR&(1<<TWINT))==0x10);
}

void main()
{
TWBR=8;
DDRB=0xff;

i2c_start();
i2c_wr(0xA0);
i2c_wr(0x1D);
i2c_wr(0x55);
i2c_stop();

_delay_ms(1000);

i2c_start();
i2c_wr(0xA0);
i2c_wr(0x1D);

i2c_start();
i2c_wr(0xA1);
PORTB=i2c_rd();
i2c_stop();
}




