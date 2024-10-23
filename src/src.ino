// #include "led.h"
#include "led_templ.h"

constexpr unsigned int PERIOD{2};
constexpr unsigned int HALF_PERIOD{PERIOD / 2};

using Builtin_LED = LED<13>;
using RGBT = RGB_LED<12, 11, 9, 10>;

void setup() {
    Builtin_LED::init();
    RGBT::init();
    Serial.begin(115200);
}

void loop() {
    Builtin_LED::on();
    RGBT::on();
    RGBT::clrRGB('r');
    delay_s(HALF_PERIOD);
    Builtin_LED::off();
    RGBT::off();
    delay_s(HALF_PERIOD);
    Serial.print(":3 ");
}