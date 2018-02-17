/*
 *	TinyLed.h
 *	Controls single led by simple on and off method.
 *	It also provides addition smart blink operation that
 *	allows to change the sate of led without the need of
 *	present state.
 *
 *	Created on	: Feb 10, 2018
 *	Author		: Balaji
 *	Email		: d.balaji.mc@gmail.com
 */
#include "TinyLed.h"

/**
 * constructor, initialize the pin that need to be driven. It setup the current
 * pin to be OUTPUT mode. The present state is maintained in a flag.
 *
 * @param	!uint8_t	led pin connected to raspberry pi.
 */
TinyLed::TinyLed(uint8_t pinNumber) {
	this->pinNumber = pinNumber;
	this->flag = false;

	pinMode(this->pinNumber, OUTPUT);
}

/**
 * Turn on the led irrespective to the current state. Pin number
 * should be mentioned in the constructor part. After turn on the
 * Flag is changed to true state.
 */
void TinyLed::on() {
	digitalWrite(this->pinNumber, HIGH);
	this->flag = true;
}


/**
 * Turn off the led irrespective to current state. This pin is also
 * need to be mentioned in constructor part. After turning off the
 * flag is changed to false state.
 */
void TinyLed::off() {
	digitalWrite(this->pinNumber, LOW);
	this->flag = false;
}

/**
 * Return the current state of the led. If it is turned on it will
 * return true and false for off state. This flags were changed
 * during the on and off functions.
 *
 * @return	!boolean	current state of the pin
 */
bool TinyLed::getState() {
	return this->flag;
}

/**
 * It toggle the led. i.e on the led if it is turned on, or off led if
 * it is turned on. It examines present state and toggle the led by
 * off or on based on the maintained flag.
 */
void TinyLed::toggle() {
	this->getState() ? off() : on();
}

/**
 * It toggles the led continuously two times with some delay mentioned in
 * parameter. Delay should be mentioned in milliseconds. If led is no state
 * then it will off the led for mentioned delay and again on the led. For led
 * off state it works on vice versa. The delay should be mentioned below
 * uint16_t i.e. 65535 milliseconds.
 *
 * @param	!uint16_t	delay time in millisecond
 */
void TinyLed::blink(uint16_t delayMills) {
	this->toggle();
	delay(delayMills);
	this->toggle();
}
