#include "tm4c123gh6pm.h"
#include "stdint.h"
#include "i2c.h"

void writeByte(uint8_t dataByte, uint8_t conditions) { //write a byte to slave
  
  
  I2C3_MDR_R = dataByte; //data to write 
  I2C3_MCS_R = conditions; //transmit writing the I2CMCS conditions  
  i2cbusycheck(); // check if I2C 3 is busy
}



uint8_t readByte(uint8_t conditions) { // read a byte from slave
  
  //i2cbusycheck(); // check if I2C 3 is busy
  //i2cerrorck(); // check for errors
  
  I2C3_MCS_R = conditions; //transmit writing the I2CMCS conditions  
  i2cbusycheck(); // check if I2C 3 is busy
  i2cerrorck(); // check for errors
  uint8_t data = I2C3_MDR_R; // read back from I2C to data
  return data;
}



void i2cbusycheck() { //check busy bit  if I2C3 MCS register
  while((I2C3_MCS_R & 0x1U) != 0) {}
  return;
}

void i2cerrorck() { //check I2C3 for error bit
  if((I2C3_MCS_R & 0x2U) != 0) {
    I2C3_MCS_R |= stop; //send stop bit
  }
  return;
}