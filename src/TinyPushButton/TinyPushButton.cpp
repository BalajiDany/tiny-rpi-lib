/*
 * TinyPushButton.cpp
 *
 *  Created on: Feb 12, 2018
 *      Author: Balaji
 */

#include "TinyPushButton.h"

TinyPushButton::TinyPushButton(uint8_t pinNumber) {
	this->pinNumber = pinNumber;
	pinMode(pinNumber, INPUT);
	pullUpDnControl(pinNumber, PUD_UP);
}

bool TinyPushButton::isPressed() {
	return (digitalRead(this->pinNumber) == LOW);
}

bool TinyPushButton::isRealesed() {
	return (digitalRead(this->pinNumber) == HIGH);
}

void TinyPushButton::waitForPress() {
	do {
		while(this->isPressed())
			delay(DEBOUNCE_DELAY);
	} while(this->isPressed());
}

void TinyPushButton::waitForRelease() {
	do {
		while(this->isRealesed())
			delay(DEBOUNCE_DELAY);
	} while(this->isRealesed());
}

uint16_t TinyPushButton::waitForSingleClick() {
	this->waitForPress();
	uint16_t startTime = millis();

	this->waitForRelease();
	return millis() - startTime;
}
