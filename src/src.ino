// #include "led.h"
#include "led_templ.h"
#include "photosensor.h"

constexpr unsigned int PERIOD{2};
constexpr unsigned int HALF_PERIOD{PERIOD / 2};


using Builtin_LED = LED<13>;
using RGBT = RGB_LED<12, 11, 9, 10, Cathode_driven>;
using PhotoSensor1 = PhotoSensor<A0>;

void setup() {
    Builtin_LED::init();
    RGBT::init();

    Serial.begin(115200);
}

void loop() {
    Builtin_LED::on();
    RGBT::on();

    RGBT::yellowLight();
    
    Builtin_LED::off();
    RGBT::yellowLightOff();
    RGBT::off();
    
    
}