/*
 * binary.h
 *
 * Created: 08-05-2020 13:51:00
 *  Author: andre
 */ 

#ifndef BINARY_H_
#define BINARY_H_

#include "UI.h"
#include "modeThree.h"

class Binary {

public:
	Binary();
	void chooseMode();
	void setModeTwoOn(char, char);
	void setModeTwoOff(char, char);
	void collectMode();
	void runMode(char[]);
	
private:

	UI ui;
	ModeThree changeModeTwo;
	
	char 
	modeType, inputCheck, settings, 
	
	modeOneDimmer[7] = {0, 0, 0, 1, 1, 1, 1},
	modeOneSwitch[7] = {0, 1, 1, 1, 0, 0, 1}, 
	
	modeTwoDimmer[7] = {0, 0, 0, 1, 1, 1, 1},
	modeTwoSwitch[7] = {0, 1, 1, 1, 0, 0, 1};
		
};




#endif /* BINARY_H_ */