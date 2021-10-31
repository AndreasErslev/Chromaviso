/*
 * binary.cpp
 *
 * Created: 08-05-2020 13:50:49
 *  Author: andre
 */ 
#include <Arduino.h>
#include "Transmitter.h"

Transmitter::Transmitter() {
	
	modeType = '0';
	settings = '0';
	inputCheck = true;
	
}

void Transmitter::chooseMode() {
	
	do {
		
		modeType = ui.printMenu();
		inputCheck = ui.printInit();
		
	} while (inputCheck);
	
	settings = '0';
	
	switch (modeType) {
		case '1': // mode one
			this->runMode(modeOneDimmer);
			this->runMode(modeOneSwitch);
		break;
		
		case '2': // mode 2
			this->runMode(modeTwoDimmer);
			this->runMode(modeTwoSwitch);
		break;
		
		case '3': //mode 3
			
			settings = ui.printSettigs();
			changeModeTwo.setDimmerOn(settings);
			
			settings = ui.printSettigs();
			changeModeTwo.setDimmerOff(settings);
			
			settings = ui.printSettigs();
			changeModeTwo.setSwitchOn(settings);
			
			settings = ui.printSettigs();
			changeModeTwo.setSwitchOff(settings);
			
			changeModeTwo.collectMode(modeTwoDimmer, modeTwoSwitch);
			break;
	}
}

void Transmitter::runMode(char sendBits[]) {
	
	for (char i = 0; i < 7; i++) {
		if (sendBits[i] == 1) {
			EICRB = 00000010;
		}
		else if (sendBits[i] == 0) {
			EICRB = 00000011;
		}
		while ((PCIFR & 1) == 0) {ui.printLoading();}
		ui.printActive();
	}
}

