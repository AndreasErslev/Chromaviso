/*
 * Transmitter.h
 *
 * Created: 14-05-2020 12:11:54
 *  Author: andre
 */ 

#ifndef TRANSMITTER_H_
#define TRANSMITTER_H_

#include "UI.h"
#include "modeThree.h"

class Transmitter {

	public:
	Transmitter();
	void chooseMode();
	void collectMode();
	void runMode(char[]);
	
	private:

	UI ui;
	ModeThree changeModeTwo;
	
	bool inputCheck;
	
	char
	modeType, settings,
	
	modeOneDimmer[7] = {0, 0, 0, 1, 1, 1, 1},
	modeOneSwitch[7] = {0, 1, 1, 1, 0, 0, 1},
	
	modeTwoDimmer[7] = {0, 0, 0, 1, 1, 1, 1},
	modeTwoSwitch[7] = {0, 1, 1, 1, 0, 0, 1};
	
};

#endif /* TRANSMITTER_H_ */