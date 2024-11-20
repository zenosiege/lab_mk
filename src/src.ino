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
    int PhotoValue = PhotoSensor1::Read();

    // RGBT::staticRGBlight();
    Serial.println(PhotoValue);
    if (PhotoValue > 400) {
        RGBT::greenLight();
    }
    else {
        RGBT::redLight();
    }
    // исправить взаимодействие светодиода с фотодатчиком
    // (почему-то при уровне 255 на красном например горит пурпурный)
    // RGBT::analogColor(255, int (PhotoSensor1::Read() / 3.2), 0)

    delay(150);
    
}