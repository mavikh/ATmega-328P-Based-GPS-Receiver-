#ifndef i2c_H
#define i2c_H

#include <avr/io.h>// AVR IO file
#include <util/delay.h>// delay function header file
#include <stdbool.h>

/* TODO: setup i2c/TWI */
//#define F_CPU	8000000UL// Define 8000000 freq. for delay function
#define F_I2C			100000UL// clock i2c
#define PSC_I2C			1		// prescaler i2c
#define SET_TWBR		(F_CPU/F_I2C-16UL)/(PSC_I2C*2UL)

/*
#include <stdint.h>///
#include <util/twi.h>///
*/

//uint8_t twi_status_register;///

void TWI_init();
void TWI_Start();
void TWI_Transmit_Add(unsigned char Add);
void TWI_Transmit_byte(unsigned char Data);
void TWI_Stop();

#endif
