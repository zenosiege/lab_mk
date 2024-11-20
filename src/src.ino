// #include "led.h"
#include "led_templ.h"
#include "photosensor.h"

constexpr unsigned int PERIOD{2};
constexpr unsigned int HALF_PERIOD{PERIOD / 2};

int howManyClicked = 0; // количество кликов
int cheatDetect = 0; // защита от "читерства", от бесконечно приложенной руки

using Builtin_LED = LED<13>;
using RGBT = RGB_LED<12, 11, 9, 10, Cathode_driven>;
using PhotoSensor1 = PhotoSensor<A0>;

void setup() {
    Builtin_LED::init();
    RGBT::init();

    Serial.begin(115200);
    Serial.println("WELCOME TO ARDUINO COMBAT!");
}

void loop() {
    Builtin_LED::on();
    RGBT::on();
    int PhotoValue = PhotoSensor1::Read();

    // RGBT::staticRGBlight();
    
    if (PhotoValue > 400) {
        cheatDetect = 0;
        RGBT::greenLight();
    }
    else if ((PhotoValue < 400) && cheatDetect == 0) {
        // если перекрываешь сенсор рукой - плюс клик
        howManyClicked += 1;
        
        // нельзя бесконечно фармить
        cheatDetect = 1;

        Serial.println(String (howManyClicked) + " Arducoins");
        RGBT::redLight();
    }
    // исправить взаимодействие светодиода с фотодатчиком
    // (почему-то при уровне 255 на красном например горит пурпурный)
    // RGBT::analogColor(255, int (PhotoSensor1::Read() / 3.2), 0)

    delay(150);
    
}