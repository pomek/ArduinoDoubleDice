#include <PCF8574.h>

class LD5161B {
  private:
    PCF8574 expander;

    /**
       Shows number "0".

       @return void
    */
    void displayZero();

    /**
       Shows number "1".

       @return void
    */
    void displayOne();

    /**
       Shows number "2".

       @return void
    */
    void displayTwo();

    /**
       Shows number "3".

       @return void
    */
    void displayThree();

    /**
       Shows number "4".

       @return void
    */
    void displayFour();

    /**
       Shows number "5".

       @return void
    */
    void displayFive();

    /**
       Shows number "6".

       @return void
    */
    void displaySix();

    /**
       Shows number "7".

       @return void
    */
    void displaySeven();

    /**
       Shows number "8".

       @return void
    */
    void displayEight();

    /**
       Shows number "9".

       @return void
    */
    void displayNine();

  public:
    /**
       The default constructor. Allows creating an empty array with
       LD5161B objects.

       @constructor
    */
    LD5161B();

    /**
       @param uint8_t deviceAddress Address to the expander.
    */
    LD5161B(const uint8_t deviceAddress);


    /**
       Turns off all the LEDs.

       @return void
    */
    void off();

    /**
       Shows given number on 7. segment display.

       @param unsigned short number Number to display.
       @return void
    */
    void show(const unsigned short number);
};
