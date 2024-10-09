#include "led.h"

constexpr unsigned int PERIOD{2};
constexpr unsigned int HALF_PERIOD{PERIOD / 2};

LED builtin_led(13);

void setup() {
    builtin_led.init();
    Serial.begin(115200);
}

void loop() {
    builtin_led.on();
    delay_s(HALF_PERIOD);
    builtin_led.off();
    delay_s(HALF_PERIOD);
    
    Serial.print(":3 ");
}