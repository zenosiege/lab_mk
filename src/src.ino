// #include "led.h"
#include "led_templ.h"

constexpr unsigned int PERIOD{2};
constexpr unsigned int HALF_PERIOD{PERIOD / 2};

using Builtin_LED = LED<13>;


void setup() {
    Builtin_LED::init();
    Serial.begin(115200);
}

void loop() {
    Builtin_LED::on();
    delay_s(HALF_PERIOD);
    Builtin_LED::off();
    delay_s(HALF_PERIOD);
    Serial.print(":3 ");
}