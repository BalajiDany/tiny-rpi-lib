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
	TinyLed(signed char);
	void on();
	void off();
	void toggle();
	bool getState();
	void blink(unsigned short int);

private:
	signed char pinNumber;
	bool flag;
};

#endif /* TINYLED_TINYLED_H_ */
