void builtin_led_init() {
    pinMode(LED_BUILTIN, OUTPUT);
}

void builtin_led_on() {
    digitalWrite(LED_BUILTIN, HIGH);  
}

void builtin_led_off() {
    digitalWrite(LED_BUILTIN, LOW); 
}

void delay_s(unsigned int s) {
    delay(s * 1000); 
}
