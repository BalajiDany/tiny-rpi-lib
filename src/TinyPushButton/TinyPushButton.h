/*
 * 	TinyPushButton.h
 * 	Maintain the push button actions. Hold the program until there
 * 	is a action in button. it also stabilized with debounce delay to filter
 *
 *	Created on	: Feb 12, 2018
 *	Author		: Balaji
 *	Email		: d.balaji.mc@gmail.com
 */
#include "../Engine.h"

#ifndef TINYPUSHBUTTON_TINYPUSHBUTTON_H_
#define TINYPUSHBUTTON_TINYPUSHBUTTON_H_

class TinyPushButton {
public:
	TinyPushButton(uint8_t pinNumber = TINY_PUSH_BUTTON);
	bool isPressed();
	bool isRealesed();
	void waitForPress();
	void waitForRelease();
	int waitForSingleClick();
private:
	uint8_t pinNumber;
};

#endif /* TINYPUSHBUTTON_TINYPUSHBUTTON_H_ */
