#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "boot.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

class DisplayManager {

  private:

    Adafruit_SSD1306 oled;

  public:

    // Constructor
    DisplayManager()
      : oled(
          SCREEN_WIDTH,
          SCREEN_HEIGHT,
          &Wire,
          -1
        ) {
    }

    // ================= OLED BEGIN =================

    void begin() {

      if (!oled.begin(
            SSD1306_SWITCHCAPVCC,
            0x3C)) {

        while (true);
      }

      oled.clearDisplay();
      oled.display();
    }


    // ================= BOOT ANIMATION =================

    void bootAnimation() {

      for (int progress = 0;
           progress <= 100;
           progress += 5) {

        oled.clearDisplay();

        // Logo
        oled.drawBitmap(
          0,
          0,
          boot_logo,
          128,
          64,
          WHITE
        );

        // Loading Bar Border
        oled.drawRect(
          14,
          54,
          100,
          8,
          WHITE
        );

        // Loading Fill
        int fillWidth =
          map(progress,
              0,
              100,
              0,
              96);

        oled.fillRect(
          16,
          56,
          fillWidth,
          4,
          WHITE
        );

        oled.display();

        delay(80);
      }
    }


    // ================= MAIN UI =================

    void showUI(
      int analogValue,
      bool signalChanged
    ) {

      static unsigned long popupTimer = 0;

      // Detect Signal Change
      if (signalChanged) {

        popupTimer = millis();
      }

      // Show popup for 10 sec
      bool showPopup =
        (millis() - popupTimer < 10000);


      // =====================================================
      // FULL SCREEN POPUP
      // =====================================================

      if (showPopup) {

        oled.clearDisplay();

        // Time Mapping
        int mappedSeconds =
          map(analogValue,
              0,
              1023,
              10,
              1800);

        int minutes =
          mappedSeconds / 60;

        int seconds =
          mappedSeconds % 60;


        // ================= TITLE =================

        oled.setTextSize(1);

        oled.setTextColor(WHITE);

        oled.setCursor(18, 2);

        oled.println("SIREN DELAY TIME");


        // ================= TIMER =================

        char timeText[10];

        sprintf(
          timeText,
          "%02d:%02d",
          minutes,
          seconds
        );

        oled.setTextSize(3);

        oled.setCursor(18, 16);

        oled.println(timeText);


        // ================= SCALE LINE =================

        oled.drawLine(
          10,
          54,
          118,
          54,
          WHITE
        );


        // ================= POINTER POSITION =================

        int pointerX =
          map(
            analogValue,
            0,
            1023,
            10,
            118
          );


        // ================= BIG STEM =================

        oled.fillRect(
          pointerX - 1,
          38,
          2,
          6,
          WHITE
          );


        // ================= BIG ARROW =================

        oled.drawTriangle(
          pointerX - 6,
          44,

          pointerX + 6,
          44,

          pointerX,
          54,

          WHITE
        );


        // ================= SCALE TEXT =================

        oled.setTextSize(1);

        oled.setCursor(0, 57);

        oled.println("10s");


        oled.setCursor(92, 57);

        oled.println("30m");


        oled.display();
      }


      // =====================================================
      // NORMAL SCREEN
      // =====================================================

      else {

        oled.clearDisplay();

        oled.setTextSize(1);

        oled.setTextColor(WHITE);


        // Title
        oled.setCursor(18, 10);

        oled.println("SYSTEM IS READY");


        // Motion Status
        oled.setCursor(10, 28);

        oled.println("NO MOTION DETECTED");


        // Delay Time
        int mappedSeconds =
          map(
            analogValue,
            0,
            1023,
            10,
            1800
          );

        int minutes =
          mappedSeconds / 60;

        int seconds =
          mappedSeconds % 60;

        char timeText[20];

        sprintf(
          timeText,
          "Delay : %02d:%02d",
          minutes,
          seconds
        );

        oled.setCursor(18, 44);

        oled.println(timeText);


        // ================= SLIDING WEBSITE =================

        static int scrollX = 128;

        oled.setCursor(
          scrollX,
          56
        );

        oled.println(
          "YouTube: Mr Jyotiprasad  [Subscribe Now]"
        );

        scrollX--;

        if (scrollX < -90) {

          scrollX = 128;
        }

        oled.display();
      }
    }


    // ================= COUNTDOWN POPUP =================

    void showCountdown(
      int remainingSeconds
    ) {

      oled.clearDisplay();

      int minutes =
        remainingSeconds / 60;

      int seconds =
        remainingSeconds % 60;

      // Popup Border
      oled.drawRoundRect(
        8,
        8,
        112,
        48,
        6,
        WHITE
      );

      // Title
      oled.setTextSize(1);

      oled.setCursor(19, 14);

      oled.println(
        "Motion Detected"
      );

      // Countdown Text
      char timeText[10];

      sprintf(
        timeText,
        "%02d:%02d",
        minutes,
        seconds
      );

      oled.setTextSize(2);

      oled.setCursor(30, 28);

      oled.println(timeText);

      // // Progress Bar
      // int fillWidth =
      //   map(
      //     remainingSeconds,
      //     0,
      //     1800,
      //     0,
      //     92
      //   );

      // oled.drawRect(
      //   18,
      //   48,
      //   92,
      //   6,
      //   WHITE
      // );

      // oled.fillRect(
      //   20,
      //   50,
      //   fillWidth,
      //   2,
      //   WHITE
      // );

      oled.display();
    }
};

#endif