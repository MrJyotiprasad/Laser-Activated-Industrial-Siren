#include "DisplayManager.h"

#define TRIGGER_BUTTON 8
#define ANALOG_PIN A0
#define AmpOut 2              //change D7

DisplayManager display;

bool countdownRunning = false;

unsigned long countdownStart = 0;
unsigned long countdownDuration = 0;

void setup() {

  pinMode(TRIGGER_BUTTON, INPUT_PULLUP);

  pinMode(AmpOut, OUTPUT);

  // Default HIGH
  digitalWrite(AmpOut, HIGH);

  display.begin();

  // Boot Animation
  display.bootAnimation();
}

void loop() {

  // ================= ANALOG SMOOTHING =================

  static int stableValue = 0;

  long total = 0;

  for (int i = 0; i < 10; i++) {

    total += analogRead(ANALOG_PIN);

    delay(2);
  }

  int analogValue = total / 10;

  // Deadband Filter
  if (abs(analogValue - stableValue) > 4) {

    stableValue = analogValue;
  }

  analogValue = stableValue;


  // ================= SIGNAL CHANGE DETECT =================

  static int previousValue = 0;

  bool signalChanged = false;

  if (abs(analogValue - previousValue) > 8) {

    signalChanged = true;

    previousValue = analogValue;
  }


  // ================= TIME MAPPING =================
  // 0-1023 => 10 sec to 30 min

  int mappedSeconds =
    map(analogValue,
        0, 1023,
        10, 1800);


  // ================= TRIGGER DETECT =================

  if (!countdownRunning &&
      digitalRead(TRIGGER_BUTTON) == HIGH) {

    countdownRunning = true;

    countdownDuration =
      (unsigned long)mappedSeconds * 1000UL;

    countdownStart = millis();

    // Hold LOW
    digitalWrite(AmpOut, LOW);

    delay(200);
  }


  // ================= COUNTDOWN MODE =================

  if (countdownRunning) {

    unsigned long elapsed =
      millis() - countdownStart;

    // Countdown Finished
    if (elapsed >= countdownDuration) {

      countdownRunning = false;

      // Release HIGH
      digitalWrite(AmpOut, HIGH);
    }

    else {

      unsigned long remainingMs =
        countdownDuration - elapsed;

      int remainingSeconds =
        remainingMs / 1000;

      display.showCountdown(
        remainingSeconds
      );
    }
  }


  // ================= NORMAL SCREEN =================

  else {

    display.showUI(
      analogValue,
      signalChanged
    );
  }

  delay(30);
}