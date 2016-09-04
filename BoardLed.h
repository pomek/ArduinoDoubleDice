class BoardLed {
  private:
    unsigned short pin;
    unsigned long time;
    bool isActive;

  public:
    /**
       The default constructor. Allows creating an empty array with
       BoardLed objects.

       @constructor
    */
    BoardLed();

    /**
       @param unsigned short pin Number of pin for controlling the LED.
       @constructor
    */
    BoardLed(const unsigned short pin);

    /**
       Switch on the LED.

       @return void
    */
    void on();

    /**
       Switch off the LED.

       @return void
    */
    void off();

    /**
       Switch current status of the LED.

       @return void
    */
    void toggle();

    /**
       Allows blinking the LED using a non-blocking interface.

       @param int interval The frequency of blinking in mili-seconds.
       @return void
    */
    void blink(const unsigned int interval);
};
