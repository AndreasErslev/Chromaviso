/*
 * modeThree.cpp
 *
 * Created: 14-05-2020 10:50:05
 *  Author: andre
 */ 

#include "modeThree.h"

ModeThree::ModeThree() {};

void ModeThree::setDimmerOn(char settings) {

	switch (settings) {
		case '1':
		dimmerOn[0] = 0;
		dimmerOn[1] = 0;
		break;
		
		case '2':
		dimmerOn[0] = 1;
		dimmerOn[1] = 0;
		break;
		
		case '3':
		dimmerOn[0] = 0;
		dimmerOn[1] = 1;
		break;
		
		case '4':
		dimmerOn[0] = 1;
		dimmerOn[1] = 1;
		break;
	}
}

void ModeThree::setDimmerOff(char settings) {

	switch (settings) {
		case '1':
		dimmerOff[0] = 0;
		dimmerOff[1] = 0;
		break;
		
		case '2':
		dimmerOff[0] = 1;
		dimmerOff[1] = 0;
		break;
		
		case '3':
		dimmerOff[0] = 0;
		dimmerOff[1] = 1;
		break;
		
		case '4':
		dimmerOff[0] = 1;
		dimmerOff[1] = 1;
		break;
	}
}

void ModeThree::setSwitchOn(char settings) {

	switch (settings) {
		case '1':
		switchOn[0] = 0;
		switchOn[1] = 0;
		break;
		
		case '2':
		switchOn[0] = 1;
		switchOn[1] = 0;
		break;
		
		case '3':
		switchOn[0] = 0;
		switchOn[1] = 1;
		break;
		
		case '4':
		switchOn[0] = 1;
		switchOn[1] = 1;
		break;
	}
}

void ModeThree::setSwitchOff(char settings) {

	switch (settings) {
		case '1':
		switchOff[0] = 0;
		switchOff[1] = 0;
		break;
		
		case '2':
		switchOff[0] = 1;
		switchOff[1] = 0;
		break;
		
		case '3':
		switchOff[0] = 0;
		switchOff[1] = 1;
		break;
		
		case '4':
		switchOff[0] = 1;
		switchOff[1] = 1;
		break;
	}
}

void ModeThree::collectMode(char dimmerMode[], char switchMode[]) {
	
	for (int n = 2; n < 6; n++) {
		if (n < 4)
			dimmerMode[n] = dimmerOn[n];
		else if (n < 6)
			dimmerMode[n] = dimmerOff[n - 2];
	}
	
	for (int n = 2; n < 6; n++) {
		if (n < 4)
			switchMode[n] = switchOn[n];
		else if (n < 6)
			switchMode[n] = switchOff[n - 2];
	}
	
}