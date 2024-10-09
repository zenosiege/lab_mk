/* Outdated code
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
*/

class LED {
    public:

        LED(int a_pin): pin{a_pin} {};

        void init() { pinMode(pin, OUTPUT); }

        void on() { digitalWrite(pin, HIGH); }

        void off() { digitalWrite(pin, LOW); }

    private:
        int pin;

};

void delay_s(unsigned int s) {
    delay(s * 1000); 
}