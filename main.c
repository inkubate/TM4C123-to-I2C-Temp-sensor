
#include "tm4c123gh6pm.h"
#include "delay.h"
#include "stdint.h"
#include "setup.h"
#include "i2c.h"
#include "PLL.h"
#include "NCT75.h"



int main()
{
  PLL_Init(); //set freq to 60MHz
  setup(); //run setup C file
  
  volatile int16_t tempread; //raw data read
  volatile float temperature; // actual calc temperature
  
  while(1) {
    tempread = (read16(NTC75_TEMP)>>4); // read temperature from default register which is 0x00
    temperature = (float)tempread*0.0625;  //convert the raw data to float of temperature. Multiply by resolution
    temperature += 0;
    delay(0xffff);  // small delay
    
    //write8(NTC75_CONFIG, NTC75_SETONESHOT); // set one shot mode which will sleep the unit
    //tempread = (read16(NTC75_ONESHOT));  //read temperature as a one shot from sleep
    // temperature = (float)tempread*0.0625;  //convert the raw data to float of temperature. Multiply by resolution
    //  temperature += 0;
    //delay(0xffff);  
    //write8(NTC75_CONFIG, (!NTC75_SETONESHOT)); // reset one shot modeback to normal
    
  }
  return 0;
}


