#define F_CPU 8000000UL
#include<avr/io.h>

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

void i2c_stop()
{
TWCR=(1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
while((TWCR&(1<<TWINT))==0x10);
}


void main()
{
TWBR=8;

i2c_start();
i2c_wr(0xD0);
i2c_wr(0x00);
i2c_wr(0x00);
i2c_stop();

i2c_start();
i2c_wr(0xD0);
i2c_wr(0x01);
i2c_wr(0x30);
i2c_stop();

i2c_start();
i2c_wr(0xD0);
i2c_wr(0x02);
i2c_wr(0x48);
i2c_stop();

i2c_start();
i2c_wr(0xD0);
i2c_wr(0x03);
i2c_wr(0x05);
i2c_stop();

i2c_start();
i2c_wr(0xD0);
i2c_wr(0x04);
i2c_wr(0x02);
i2c_stop();

i2c_start();
i2c_wr(0xD0);
i2c_wr(0x05);
i2c_wr(0x12);
i2c_stop();

i2c_start();
i2c_wr(0xD0);
i2c_wr(0x06);
i2c_wr(0x93);
i2c_stop();
}
