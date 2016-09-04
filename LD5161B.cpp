#include <Wire.h>
#include <PCF8574.h>
#include "./LD5161B.h"

/**
   The default constructor. Allows creating an empty array with
   LD5161B objects.

   @constructor
*/
LD5161B::LD5161B() {
  // This constructor is empty.
}

/**
   @param uint8_t deviceAddress Address to the expander.
*/
LD5161B::LD5161B(const uint8_t deviceAddress) {
  this->expander.begin(deviceAddress);

  for (int i = 0; i < 8; ++i) {
    this->expander.pinMode(i, OUTPUT);
    this->expander.digitalWrite(i, HIGH);
  }
}

/**
   Turns off all the LEDs.

   @return void
*/
void LD5161B::off() {
  for (int i = 0; i < 8; ++i) {
    this->expander.digitalWrite(i, HIGH);
  }
}

/**
   Shows given number on 7. segment display.

   @param unsigned short number Number to display.
   @return void
*/
void LD5161B::show(const unsigned short number) {
  switch (number) {
    case 0:
      this->displayZero();
      break;
    case 1:
      this->displayOne();
      break;
    case 2:
      this->displayTwo();
      break;
    case 3:
      this->displayThree();
      break;
    case 4:
      this->displayFour();
      break;
    case 5:
      this->displayFive();
      break;
    case 6:
      this->displaySix();
      break;
    case 7:
      this->displaySeven();
      break;
    case 8:
      this->displayEight();
      break;
    case 9:
      this->displayNine();
      break;
    default:
      this->off();
  }
}

/**
   Shows number "0".

   @return void
*/
void LD5161B::displayZero() {
  this->off();

  this->expander.digitalWrite(1, LOW);
  this->expander.digitalWrite(2, LOW);
  this->expander.digitalWrite(3, LOW);
  this->expander.digitalWrite(4, LOW);
  this->expander.digitalWrite(5, LOW);
  this->expander.digitalWrite(7, LOW);
}

/**
   Shows number "1".

   @return void
*/
void LD5161B::displayOne() {
  this->off();

  this->expander.digitalWrite(1, LOW);
  this->expander.digitalWrite(4, LOW);
}

/**
   Shows number "2".

   @return void
*/
void LD5161B::displayTwo() {
  this->off();

  this->expander.digitalWrite(2, LOW);
  this->expander.digitalWrite(3, LOW);
  this->expander.digitalWrite(4, LOW);
  this->expander.digitalWrite(5, LOW);
  this->expander.digitalWrite(6, LOW);
}

/**
   Shows number "3".

   @return void
*/
void LD5161B::displayThree() {
  this->off();

  this->expander.digitalWrite(1, LOW);
  this->expander.digitalWrite(2, LOW);
  this->expander.digitalWrite(4, LOW);
  this->expander.digitalWrite(5, LOW);
  this->expander.digitalWrite(6, LOW);
}

/**
   Shows number "4".

   @return void
*/
void LD5161B::displayFour() {
  this->off();

  this->expander.digitalWrite(1, LOW);
  this->expander.digitalWrite(4, LOW);
  this->expander.digitalWrite(6, LOW);
  this->expander.digitalWrite(7, LOW);
}

/**
   Shows number "5".

   @return void
*/
void LD5161B::displayFive() {
  this->off();

  this->expander.digitalWrite(1, LOW);
  this->expander.digitalWrite(2, LOW);
  this->expander.digitalWrite(5, LOW);
  this->expander.digitalWrite(6, LOW);
  this->expander.digitalWrite(7, LOW);
}

/**
   Shows number "6".

   @return void
*/
void LD5161B::displaySix() {
  this->off();

  this->expander.digitalWrite(1, LOW);
  this->expander.digitalWrite(2, LOW);
  this->expander.digitalWrite(3, LOW);
  this->expander.digitalWrite(5, LOW);
  this->expander.digitalWrite(6, LOW);
  this->expander.digitalWrite(7, LOW);
  this->expander.digitalWrite(0, LOW);
}

/**
   Shows number "7".

   @return void
*/
void LD5161B::displaySeven() {
  this->off();

  this->expander.digitalWrite(1, LOW);
  this->expander.digitalWrite(4, LOW);
  this->expander.digitalWrite(5, LOW);
}

/**
   Shows number "8".

   @return void
*/
void LD5161B::displayEight() {
  this->off();

  this->expander.digitalWrite(1, LOW);
  this->expander.digitalWrite(2, LOW);
  this->expander.digitalWrite(3, LOW);
  this->expander.digitalWrite(4, LOW);
  this->expander.digitalWrite(5, LOW);
  this->expander.digitalWrite(6, LOW);
  this->expander.digitalWrite(7, LOW);
}

/**
   Shows number "9".

   @return void
*/
void LD5161B::displayNine() {
  this->off();

  this->expander.digitalWrite(1, LOW);
  this->expander.digitalWrite(2, LOW);
  this->expander.digitalWrite(4, LOW);
  this->expander.digitalWrite(5, LOW);
  this->expander.digitalWrite(6, LOW);
  this->expander.digitalWrite(7, LOW);
  this->expander.digitalWrite(0, LOW);
}
