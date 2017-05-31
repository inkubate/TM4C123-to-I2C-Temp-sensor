#ifndef __i2c__
#define __i2c__

#define run (1<<0)
#define start (1<<1)
#define stop (1<<2)
#define ack (1<<3)

void i2cbusycheck(); //check I2C3 busy
void i2cerrorck(); //check error bit
void writeByte(uint8_t dataByte, uint8_t conditions);
uint8_t readByte(uint8_t conditions);

#endif // __i2c__