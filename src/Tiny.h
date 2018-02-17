/*
 *	Tiny.h
 *	Includes all the libraries in present directory
 *
 *	Created on	: Feb 10, 2018
 *	Author		: Balaji
 *	Email		: d.balaji.mc@gmail.com
 */

#ifndef TINY_H_
#define TINY_H_
#include "TinyLed/TinyLed.h"
#include "TinyPushButton/TinyPushButton.h"

namespace Tiny {

	// Initial setup for wiringPi
	int setup() {
		return wiringPiSetup();
	}

	// #Instance
	TinyLed led;

	// #Instance
	TinyPushButton pushButton;
}

#endif /* TINY_H_ */
