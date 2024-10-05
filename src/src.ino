/* Outdated code
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  
  delay(1000);                      
  digitalWrite(LED_BUILTIN, LOW);   
  delay(1000);                     
}
*/

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