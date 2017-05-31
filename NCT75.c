#include "tm4c123gh6pm.h"
#include "stdint.h"
#include "i2c.h"
#include "stdint.h"
#include "delay.h"
#include "NCT75.h"



void write8 (uint8_t reg, uint32_t value) // send regsiter address and value to write
{ 
  I2C3_MSA_R = (NCT75_ADDRESS << 1); //Specify the slave address and that the next operation is a SEND. Bit '0' = 0
  writeByte(reg, (run|start)); // choose command to slave. Start and run
  writeByte(value & 0xFF, (run|stop)); // choose command to slave. Run stop
} 




uint8_t read8(uint8_t reg) { // send regsiter address to read then read one byte back
  uint16_t bt; //read back byte
  
  I2C3_MSA_R = (NCT75_ADDRESS << 1); //Specify the slave address and that the next operation is a SEND. Bit '0' = 0
  writeByte(reg, (run|start)); // choose command to slave. Start and run
  
  I2C3_MSA_R = ((NCT75_ADDRESS << 1)|0x1); //Specify the slave address and that the next operation is a RECEIVE. Bit '0' = 1
  bt = (readByte(run|stop|ack)); // Read data back. run, ack, stop
  
  return bt; 
} 




uint16_t read16(uint8_t reg) {  // send regsiter address to read then read two bytes back
  uint16_t MSB; //int for MS byte. Use 16 bit to avoid casting issues in later arithmatic
  uint16_t LSB; //int for LS byte
  int16_t combined; //combined to 16bit
  
  I2C3_MSA_R = (NCT75_ADDRESS << 1); //Specify the slave address and that the next operation is a SEND. Bit '0' = 0
  writeByte(reg, (run|start)); // choose command to slave. Start and run
  
  I2C3_MSA_R = ((NCT75_ADDRESS << 1)|0x1); //Specify the slave address and that the next operation is a RECEIVE. Bit '0' = 1
  MSB = (readByte(run|start|ack)); // Read data back. run, start, ack
  LSB = (readByte(run|stop|ack)); // Read data back. run, ack, stop
  
  combined = ((MSB << 8) | LSB); // combine MSB and LSB to one 16bit. MSB is already 16bit to avoid cast issues

  return combined; 
} 


