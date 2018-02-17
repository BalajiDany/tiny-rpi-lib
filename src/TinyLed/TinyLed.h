/*
 *	TinyLed.h
 *	It is an Independent header. i.e includes only
 *	the basic imports (Engine.h)
 *
 *	Created on	: Feb 10, 2018
 *	Author		: Balaji
 *	Email		: d.balaji.mc@gmail.com
 */
#include "../Engine.h"

#ifndef TINYLED_TINYLED_H_
#define TINYLED_TINYLED_H_

/**
 * class definition
 */
class TinyLed {
// #public
public:
	TinyLed(uint8_t pinNumber = TINY_LED_PIN);	// #constructor
	void on();
	void off();
	void toggle();
	bool getState();
	void blink(uint16_t delayMills);

// #private
private:
	uint8_t pinNumber;
	bool flag;
};

#endif /* TINYLED_TINYLED_H_ */
