/*
 *	TinyLed.h
 *	Controls single led by simple on and off method.
 *	It also provides addition smart blink operation that
 *	allows to change the sate of led without considering the
 *	current state.
 *
 *	Created on	: Feb 10, 2018
 *	Author		: Balaji
 *	Email		: d.balaji.mc@gmail.com
 */
#include "TinyLed.h"

TinyLed::TinyLed(uint8_t pinNumber) {
	this->pinNumber = pinNumber;
	this->flag = false;

	pinMode(this->pinNumber, OUTPUT);
}

void TinyLed::on() {
	digitalWrite(this->pinNumber, HIGH);
	this->flag = true;
}

void TinyLed::off() {
	digitalWrite(this->pinNumber, LOW);
	this->flag = false;
}

bool TinyLed::getState() {
	return this->flag;
}

void TinyLed::toggle() {
	this->getState() ? off() : on();
}

void TinyLed::blink(uint16_t delayMills) {
	this->toggle();
	delay(delayMills);
	this->toggle();
}
