/*
 * TinyPushButton.cpp
 * Manage single pole push button. One end is need to be
 * connected to raspberry pi and other end should be grounded.
 * Initially it pulls up the pin register to hold HIGH at the
 * pin. If button is pressed the pin will be grounded and
 * current state of pin will be toggled to LOW. This allows to
 * get the current state of the button eiter it is pressed or
 * released.
 *
 *	Created on	: Feb 10, 2018
 *	Author		: Balaji
 *	Email		: d.balaji.mc@gmail.com
 */

#include "TinyPushButton.h"

/**
 * constructor to initialize the pin as push button by pulling up as
 * input pin. This pin number need to be mentioned while instantiating.
 * This pin number is maintained under the private variable.
 *
 * @param	!uint8_t	push button pin that connects to raspberry pi
 */
TinyPushButton::TinyPushButton(uint8_t pinNumber) {
	this->pinNumber = pinNumber;
	pinMode(pinNumber, INPUT);
	pullUpDnControl(pinNumber, PUD_UP);
}

/**
 * isPressed method scan the pin and return state. Since the pin is pulled up
 * it remains high. When the button is pressed, pin is grounded and pin state
 * will be LOW.
 *
 * @return	!boolean	return the button state, true if pressed.
 */
bool TinyPushButton::isPressed() {
	return (digitalRead(this->pinNumber) == LOW);
}

/**
 * isRealesed method scan the pin only once and return true if it is high.
 * When user not presses the button pin and ground will be disconnected.
 * Since the pin is pulled up it will remain high.
 *
 * @return	!boolean	return the button state, true if not pressed.
 */
bool TinyPushButton::isRealesed() {
	return (digitalRead(this->pinNumber) == HIGH);
}

/**
 * It remains wait until the button is pressed. A default debounce delay of 10 millisecond
 * will be added to avoid flickering of voltage drop when pressing the button.
 * This filter helps to sense only stable human press.
 */
void TinyPushButton::waitForPress() {
	do {
		while(this->isPressed())
			delay(DEBOUNCE_DELAY);
	} while(this->isPressed());
}

/**
 * It remains wait until the button is released. Default debounce is provided
 * to filter the sharp change in voltage. The scope of this method will get
 * returns only when button is released continuously for 10 millisecond
 * i.e debounce delay.
 */
void TinyPushButton::waitForRelease() {
	do {
		while(this->isRealesed())
			delay(DEBOUNCE_DELAY);
	} while(this->isRealesed());
}

/**
 * waitForSingleClik method continues the scope until the user make complete action in
 * button i.e press and release of button. It also return button pressed time.
 *
 * @return	!uint16_t period of button being pressed.
 */
uint16_t TinyPushButton::waitForSingleClick() {
	this->waitForPress();
	uint32_t startTime = millis();

	this->waitForRelease();
	return millis() - startTime;
}
