#include "led.h"

constexpr unsigned int PERIOD{2};
constexpr unsigned int HALF_PERIOD{PERIOD / 2};

void setup() {
    builtin_led_init();
}

void loop() {
    builtin_led_on();
    delay_s(HALF_PERIOD);
    builtin_led_off();
    delay_s(HALF_PERIOD);
}