/*
 * modeThree.h
 *
 * Created: 14-05-2020 10:50:31
 *  Author: andre
 */ 


#ifndef MODETHREE_H_
#define MODETHREE_H_

class ModeThree {
	
public:
	ModeThree();
	void setDimmerOn(char);
	void setDimmerOff(char);
	void setSwitchOn(char);
	void setSwitchOff(char);
	void collectMode(char[], char[]);
	
private:

	char

	dimmerOn[2],
	dimmerOff[2],
	
	switchOn[2],
	switchOff[2];
	
};



#endif /* MODETHREE_H_ */