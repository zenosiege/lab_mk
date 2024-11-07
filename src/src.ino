// #include "led.h"
#include "led_templ.h"

constexpr unsigned int PERIOD{2};
constexpr unsigned int HALF_PERIOD{PERIOD / 2};


using Builtin_LED = LED<13>;
using RGBT = RGB_LED<12, 11, 9, 10, Cathode_driven>;

void setup() {
    Builtin_LED::init();
    RGBT::init();
    
    Serial.begin(115200);
}

void loop() {
    /*
    int randRed;
    int randGreen;
    int randBlue;
    int start = 0;
    int end = 255;

    randRed = rand() % (end - start + 1) + start;
    randGreen = rand() % (end - start + 1) + start;
    randBlue = rand() % (end - start + 1) + start;
    */

   //сделать переливание цветов, опираясь на ргб-палитру
    Builtin_LED::on();
    RGBT::on();

    RGBT::staticRGBlight();
    
    delay(150);
    Serial.print(":3 ");
}