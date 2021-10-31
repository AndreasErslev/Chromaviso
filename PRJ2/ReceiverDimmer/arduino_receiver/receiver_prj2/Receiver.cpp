/*
 * Reciever.cpp
 *
 * Created: 15-05-2020 12:59:21
 *  Author: andre
 */ 

#include "Receiver.h"

void initInterrupt () {
	
	EIMSK = 0b00010000;    // External interupt, INT4
	EICRB = 0b00000011;    // Rising edge interrupt, default
	
}

void initPWM() {
	
	//    Mode = 2 (PWM, Phase Correct, 9-bit)
	//    Set OC3A on match down counting / Clear OC3A on match counting
	//    Clock prescaler = 1
	TCCR3A = 0b11000010;
	TCCR3B = 0b00000001;
	
}

int binToDec(char bitArray[], int start, int end)
{
	int binNum = 0;
	int bitCount = 1;
	for(int i = 0; i < end; i++)
	{
		binNum += bitArray[start - i]*(1000/i);
		bitCount *= 10;
	}
	
	//Konvertere tal fra binær syntax til decimal
	int decNum = 0, rem, base = 1;
	while (binNum > 0)
	{
		rem = binNum % 10;
		decNum = decNum + rem * base;
		base = base * 2;
		binNum = binNum / 10;
	}
	
	return decNum;
}

void inputReader(char loadBits[]) {

	// Læser bit 4 og 5 for off
	if (loadBits[1] == 0 && loadBits[8] == 0) {
		// Læser bit 4 og 5 for bestemmelse af start 
		int turnOnDec = binToDec(loadBits, 2, 3);
		delay(3600000 * turnOnDec);
		// PWM tænd	
		
		// Sætter PWM styrke maks
		OCR3A = 102 * binToDec(loadBits, 10, 13);
		
		// Læser bit 4 og 5 for bestemmelse af slut tid
		int turnOffDec = binToDec(loadBits, 4, 5);
		delay(3600000 * turnOffDec);
		
		// Slukker switch
		OCR3A = 0;
	}
}

