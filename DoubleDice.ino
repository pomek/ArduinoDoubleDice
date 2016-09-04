#include <stdlib.h>
#include "./BoardLed.h"
#include "./LD5161B.h"

#define GREEN 0
#define YELLOW_LEFT 1
#define YELLOW_MIDDLE 2
#define YELLOW_RIGHT 3
#define RED 4
#define BUTTON 8

BoardLed *leds;
LD5161B greenDisplay;
LD5161B redDisplay;
bool isActive;
bool isDone;
unsigned long beginTime;
unsigned short redNumber;
unsigned short greenNumber;

void setup() {
  leds = new BoardLed[5];
  greenDisplay = LD5161B(0x20);
  redDisplay = LD5161B(0x21);

  // Leds are connected with pins 9 - 13.
  for (int i = 0; i < 5; ++i) {
    leds[i] = BoardLed(i + 9);
  }

  pinMode(BUTTON, INPUT_PULLUP);
  randomSeed(analogRead(0));
}

void loop() {
  // Waits for a new process.
  if (!isActive && digitalRead(BUTTON) == LOW) {
    greenDisplay.off();
    redDisplay.off();

    redNumber = 0;
    greenNumber = 0;
    isActive = true;
    isDone = false;
    beginTime = millis();
  }

  // Numbers are generated. Just display them.
  if (isDone) {
    greenDisplay.show(greenNumber);
    redDisplay.show(redNumber);
  }

  // The process has been began.
  if (isActive) {
    unsigned long timeDifferent = millis() - beginTime;

    // After 3 secs. until the began of process, display generated numbers.
    if (timeDifferent > 3000) {
      // And switch off loader.
      for (int i = 0; i < 5; ++i) {
        leds[i].off();
      }

      isDone = true;
      isActive = false;
    }

    // LEDs loader...
    if (timeDifferent < 3000) {
      unsigned short secondModulo = timeDifferent % 1000;

      // Generate the red number.
      if (!redNumber && timeDifferent > 500 && timeDifferent < 1000) {
        redNumber = random(0, 6) + 1;
      }

      // Generate the green number.
      if (!greenNumber && timeDifferent > 1000 && timeDifferent < 1500) {
        greenNumber = random(0, 6) + 1;
      }

      if (secondModulo >= 0 && secondModulo < 100) {          // [X][ ][ ][ ][ ]
        leds[GREEN].on();
      } else if (secondModulo >= 100 && secondModulo < 200) { // [X][X][ ][ ][ ]
        leds[YELLOW_LEFT].on();
      } else if (secondModulo >= 200 && secondModulo < 300) { // [X][X][X][ ][ ]
        leds[YELLOW_MIDDLE].on();
      } else if (secondModulo >= 300 && secondModulo < 400) { // [X][X][X][X][ ]
        leds[YELLOW_RIGHT].on();
      } else if (secondModulo >= 400 && secondModulo < 500) { // [X][X][X][X][X]
        leds[RED].on();
      } else if (secondModulo >= 500 && secondModulo < 600) { // [X][X][X][X][ ]
        leds[RED].off();
      } else if (secondModulo >= 600 && secondModulo < 700) { // [X][X][X][ ][ ]
        leds[YELLOW_RIGHT].off();
      } else if (secondModulo >= 700 && secondModulo < 800) { // [X][X][ ][ ][ ]
        leds[YELLOW_MIDDLE].off();
      } else if (secondModulo >= 800 && secondModulo < 900) { // [X][ ][ ][ ][ ]
        leds[YELLOW_LEFT].off();
      } else {                                                // [ ][ ][ ][ ][ ]
        leds[GREEN].off();
      }
    }
  }

  // Delay all the actions 75ms.
  delay(75);
}
