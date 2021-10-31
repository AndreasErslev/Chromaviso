/*
 * UI.cpp
 *
 * Created: 08-05-2020 11:10:22
 *  Author: andre
 */ 
/*
 * UI.cpp
 *
 * Created: 01-05-2020 14:03:54
 *  Author: andre
 */ 

#include <Arduino.h>
#include "UI.h"

UI::UI() {n = '0'; i = '0'; module = '1';}

char UI::printMenu() {
	
	this->serialFlush();
	if (n == '0') 
		Serial.println("Hello!");
	
	Serial.println("What would you like to do?");
	Serial.println("1. Choose mode one");
	Serial.println("2. Choose mode two");
	Serial.println("3. Change mode two");
	Serial.print("Choice: ");
	while (1) {	
		if (Serial.available() > 0) {
			
			n = Serial.read();

			if (n != '0') {
				
				// Reset PuTTy konsol
				Serial.write(12);
				delay(500);
				
				return n;
			}
		}
	}
}
char UI::printSettigs() {
	
	switch (module) {
		case '1':
			Serial.println("Choose what time the Dimmer should turn on: ");
			Serial.println("1. 1 hour ");
			Serial.println("2. 2 hours ");
			Serial.print("Choice: ");
		break;
		
		case '2':
			Serial.println("Choose what time the Dimmer should turn off: ");
			Serial.print("Choice: ");
		break;		
		
		case '3':
			Serial.println("Choose what time the Switch should turn on: ");
			Serial.print("Choice: ");
		break;
		
		case '4':
			Serial.println("Choose what time the Switch should turn off: ");
			Serial.print("Choice: ");
		break;
				
	}
	
	this->serialFlush();
	
	while (1) {
		if (Serial.available() > 0) {
			
			i = Serial.read();
			
			if (i != '0') {
				module++;
				return i;
			}
		}
	}
}

bool UI::printInit() {
		
	if (n == '1') {
		Serial.println("Mode one is initializing:\n");
		this->printLoading();
		return false;
	}
	else if(n == '2') {
		Serial.println("Mode two is initializing:\n");
		this->printLoading();
		return false;
	}
	else if(n == '3') {
		Serial.println("Change your settings for mode two:\n");
		this->printLoading();
		return false;
	}	
	else {
		this->printWrongInput();
		return true;

	}
	
}
void UI::printLoading() {
	
	
	if (k == 4) {
		Serial.print("\n");
		k++;
	}
	else if (k > 7) {
		k = 0;
		Serial.print("\n");
	}
	
	Serial.print("Loading ");
	PORTB |= (1 << k); k++;
	
	for (char q = 0; q < 3; q++) {
		_delay_ms(125);
		Serial.print(". ");
	}
	
	_delay_ms(500);
	
}
void UI::printActive() const {
	
	// Reset PuTTy konsol
	Serial.write(12);
	delay(500);
	
	if (n == '1') {
		Serial.println("Mode one is now active");
		PORTB = 0b00000010;
	}
	else if(n == '2') {
		Serial.println("Mode two is now active");
		PORTB = 0b00000010;
	}
	else if (n == '3') 
		Serial.println("Mode 2 is now changed");
	
	Serial.println("- - - - - - - - - - ");
	
}
void UI::printWrongInput() const {
	
	Serial.println("You have chosen an input, that is not valid. Try again.");
	
}

void UI::serialFlush() const {
	_delay_ms(250);
	while(Serial.available() > 0) {
		char q = Serial.read();
	}
}