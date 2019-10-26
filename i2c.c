#include "i2c.h"

/*
 * Initialize and Enable TWI(I2C)
 * */
void TWI_init(){
	// set prescaller to 1
	TWSR = 0x00;// clear Status Reg.
//	TWBR = 0x0C;// set Bit Rate Reg. //set SCL to 400KH
	TWBR = (uint8_t)SET_TWBR;

	// enable TWI(I2C)
	TWCR = (1<<TWEN);// control Reg.
}

/*
 * Send Start condition
 * */
void TWI_Start(){
	// clear TWI interrupt flag, Put start condition on SDA, Enable TWI
	TWCR =(1<< TWINT)| (1<< TWSTA) | (1<< TWEN);// send Start Condition

	// wait till start condition is transmitted
	while((TWCR & (1<<TWINT)) == 0);// wait for TWINT=1 in the+ TWCR Register

	// check for the acknowledgment (start transmitted)
	while((TWSR & 0xF8)!= 0x08);
}

/*
 * Send Address of receiver
 * */
void TWI_Transmit_Add(unsigned char Add){
	TWDR = Add;
	TWCR = (1<<TWINT) |	(1<<TWEN);// Clear TWINT bit in TWCR to start transmission of address

	// wait for TWINT Flag set
	while (!(TWCR & (1<<TWINT)));// TWINT=1: Add transmitted and Ack/NAck received
	while ((TWSR & 0xF8) !=	0x18);
}

void TWI_Transmit_byte(unsigned char Data){
	TWDR = Data;
	TWCR = (1<<TWINT) |	(1<<TWEN);// Clear TWINT bit in TWCR to	start transmission of data
	// Wait for TWINT Flag set.
	while (!(TWCR & (1<<TWINT)));// TWINT=1: DATA transmitted, and ACK/NACK received

	while((TWSR & 0xF8) !=	0x28);
}

void TWI_Stop(){
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);// Transmit STOP condition
    while(TWCR & (1<<TWSTO));////
}
