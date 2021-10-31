/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "Receiver.h"

/*End of auto generated code by Atmel studio */

//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio

void setup() {
  // put your setup code here, to run once:
	Serial.begin(9600); // opens serial port, sets data rate to 9600 bps

}

static volatile char loadBits[7];
static volatile int count = 0;

ISR(INT4_vect) {
	
	// Rising edge
	
	if (digitalRead(2) == 1) // Set signal fra envalope
	loadBits[count++] = '1';
	
	else if (digitalRead(2) == 0) // Set signal fra envalope
	loadBits[count++] = '0';
	
}

void loop() {

	initInterrupt();
	initPWM();
	char sendBits[7];
	while (1) {
		// Activate interrupt
		sei(); //global interupt enable
		while (count < 7) {}
		// Deaktivate interrupt
		cli(); //global interrupt disable
		
		for (int n = 0; n < 14; n++)
			sendBits[n] = loadBits[n];
		
		inputReader(loadBits);
		count = 0;
		
	}

}
