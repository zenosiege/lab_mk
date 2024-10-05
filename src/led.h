namespace Builtin_led {

void init() {
    pinMode(LED_BUILTIN, OUTPUT);
}

void on() {
    digitalWrite(LED_BUILTIN, HIGH);  
}

void off() {
    digitalWrite(LED_BUILTIN, LOW); 
}

}

void delay_s(unsigned int s) {
    delay(s * 1000); 
}