#include "led.h"

void setup() {
    builtin_led_init();
}

void loop() {
    builtin_led_on();
    delay_s(1);
    builtin_led_off();
    delay_s(1);
}