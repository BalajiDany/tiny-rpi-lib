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
#include "../Engine.h"

#ifndef TINYLED_TINYLED_H_
#define TINYLED_TINYLED_H_

class TinyLed {
public:
	TinyLed(uint8_t pinNumber = TINY_LED_PIN);
	void on();
	void off();
	void toggle();
	bool getState();
	void blink(uint16_t delayMills);

private:
	signed char pinNumber;
	bool flag;
};

#endif /* TINYLED_TINYLED_H_ */
