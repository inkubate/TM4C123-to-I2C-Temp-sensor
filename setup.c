
#include "tm4c123gh6pm.h"
#include "stdint.h"

void setup(){ 
  
  ///* I2C Setup *\\\\
  
  SYSCTL_RCGCI2C_R |= 0x8U;      //enable clock to I2C module 3 (clock gating ctl which is bit 3 to 1)
  SYSCTL_RCGCGPIO_R |= 0x8U;      //enable clock to GPIO bank D (clock gating ctl which is bit 3 to 1)
  
  
  // Configure SCL
  GPIO_PORTD_AFSEL_R |= 0x03U;      // alt function selected on D0 and D1
  GPIO_PORTD_DEN_R = 0x03U;      // digital enable D0 and D1
  GPIO_PORTD_PCTL_R = 0x33U;      // port control - 0x3 for I2C - (bits 0 to 3 for pin D0)(bits 4 to 7 for pin D1)
  
  // Configure SDA
  GPIO_PORTD_ODR_R = 0x02U;      // D1 open drain
  
  I2C3_MCR_R  = 0x10U;      // initialise I2C master page 1016 datasheet
  I2C3_MTPR_R = (7<<0);     // Set the desired SCL clock speed of 100 Kbps based on 60MHz system clock page 1016 0x09
}