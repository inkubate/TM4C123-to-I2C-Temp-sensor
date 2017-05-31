#ifndef __NCT75__
#define __NCT75__

/* functon declarations */
void write8 (uint8_t reg, uint32_t value);
uint8_t read8(uint8_t reg);
uint16_t read16(uint8_t reg);


/* register address definitions */
#define NCT75_ADDRESS 0x48 /*the I2C address of the device */

//Register pointer values
#define NTC75_TEMP 0x00 /* reg address od temp value */
#define NTC75_CONFIG 0x01 /* Config register */
#define NTC75_THYST 0x02 /* THYST register */
#define NTC75_TOS 0x03 /* TOS register*/
#define NTC75_ONESHOT 0x04 /* one shot read regsiter*/

//setting values for register
#define NTC75_SETONESHOT 0x20 //set bit 5 of the config register (0x01) to enable one shot mode


#endif // __NCT75__