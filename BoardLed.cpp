#include <Arduino.h>
#include "./BoardLed.h"

/**
   The default constructor. Allows creating an empty array with
   BoardLed objects.

   @constructor
*/
BoardLed::BoardLed() {
  // This constructor is empty.
}

/**
   @param unsigned short pin Number of pin for controlling the LED.
   @constructor
*/
BoardLed::BoardLed(const unsigned short pin) {
  pinMode(pin, OUTPUT);

  this->pin = pin;
  this->isActive = (HIGH == digitalRead(pin));
  this->time = millis();
}

/**
   Switch on the LED.

   @return void
*/
void BoardLed::on() {
  this->isActive = true;
  digitalWrite(this->pin, HIGH);
}

/**
   Switch off the LED.

   @return void
*/
void BoardLed::off() {
  this->isActive = false;
  digitalWrite(this->pin, LOW);
}

void BoardLed::toggle() {
  if (this->isActive) {
    this->off();
  } else {
    this->on();
  }
}

/**
   Allows blinking the LED using a non-blocking interface.

   @param unsigned int interval The frequency of blinking in mili-seconds.
   @return void
*/
void BoardLed::blink(const unsigned int interval) {
  unsigned long currentMillis = millis();

  if (currentMillis - this->time <= interval) {
    return;
  }

  this->time = currentMillis;
}
