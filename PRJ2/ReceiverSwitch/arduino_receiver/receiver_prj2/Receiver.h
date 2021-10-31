/*
 * Receiver.h
 *
 * Created: 15-05-2020 12:59:35
 *  Author: andre
 */ 


#ifndef RECEIVER_H_
#define RECEIVER_H_

#include <Arduino.h>
#include <avr/interrupt.h>

void initInterrupt();
void initPWM();
int binToDec(char[], int, int);
void inputReader(char[]);

#endif /* RECEIVER_H_ */