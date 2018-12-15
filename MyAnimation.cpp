#include <Adafruit_NeoPixel.h>
#include "MyAnimation.h"

long blueColor = 0;
long blueEnd = 0;
long blueStart = 0;
long greenColor = 0;
long greenEnd = 0;
long greenStart = 0;
long redColor = 0;
long redEnd = 0;
long redStart = 0;
int cycle1 = 1;
int cycle3 = 10;
int pixelNum = 0;
int mult = 1;

void color () {
  greenStart = greenColor;
  blueStart = blueColor;
  redStart = redColor;
  greenEnd = random(255);
  redEnd = greenEnd;
  blueEnd = greenEnd;
}

void visColor (int numPixel) {
  greenColor = greenStart + ((greenEnd - greenStart) * cycle1 / cycle3);
  blueColor = blueStart + ((blueEnd - blueStart) * cycle1 / cycle3);
  redColor = redStart + ((redEnd - redStart) * cycle1 / cycle3);
  if (cycle1 == cycle3) {
    cycle1 = 1;
    color();
    if (pixelNum < numPixel) {
      pixelNum = pixelNum + 1;
    }
    else {
      pixelNum = 1;
    }
  }
}

void MyAnimation::reset(Adafruit_NeoPixel *strip) {
  strip->begin();
  setTimeout(waitTime);
}

void MyAnimation::draw(Adafruit_NeoPixel *strip) {
  if (isTimedout()) {
    cycle1 = cycle1 + 1;
    strip->setPixelColor((3 * mult - (pixelNum + 1)), (255 - redColor), (255 - greenColor), (255 - blueColor));
    strip->setBrightness(100);
    visColor(4);
    setTimeout(waitTime);
    mult = mult + 1;
  }
  if (mult > 12) {
    mult = 0;
  }
}
