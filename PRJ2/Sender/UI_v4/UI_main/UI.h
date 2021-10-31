/*
 * IncFile1.h
 *
 * Created: 01-05-2020 13:50:34
 *  Author: andre
 */ 

#ifndef UI_H
#define UI_H

class UI {
	
public:
	UI();
	char printMenu();
	char printSettigs();
	bool printInit();
	void printLoading();
	void printActive() const;
	void printWrongInput() const;
	void serialFlush() const;
	
private:
	char n, i, k, module;
	
	};

#endif /* INCFILE1_H_ */