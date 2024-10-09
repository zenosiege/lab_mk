#include "led.h"

constexpr unsigned int PERIOD{2};
constexpr unsigned int HALF_PERIOD{PERIOD / 2};

LED builtin_led(13);
RGB_LED another_led(12, 11, 9, 10);

void setup() {
    builtin_led.init();
    Serial.begin(115200);
}

void loop() {
    builtin_led.on();
    another_led.on();
    another_led.clrRGBon('w');
    delay_s(HALF_PERIOD);
    builtin_led.off();
    another_led.off();
    another_led.clrRGBoff('w');
    delay_s(HALF_PERIOD);
    
    Serial.print(":3 ");
}