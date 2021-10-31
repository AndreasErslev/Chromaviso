/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

// Tilføj biblioteker
#include "setup.h"
#include "Transmitter.h"


//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio

//Init interrupt
//Init PWM
//Init CTC

//Set objekter / variabler
Transmitter startMode;

//Set interrupts
ISR(INT4_vect) {
	
	OCR3A = 65.66;
	EICRB = 00000000;
	
} 

void loop() {
	
	//Åben port B
	DDRB = 0xFF;
	
	do {
	startMode.chooseMode(); // Kører valgte mode
	} while (1)	;
}
