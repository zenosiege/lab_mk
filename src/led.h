
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

class RGB_LED {
    public:

        RGB_LED(int a_pin, int r_pin, int g_pin, int b_pin): pin{a_pin}, rpin{r_pin}, gpin{g_pin}, bpin{b_pin} {};

        void init() { pinMode(pin, OUTPUT); pinMode(rpin, OUTPUT); pinMode(gpin, OUTPUT); pinMode(bpin, OUTPUT);}

        void on() { digitalWrite(pin, HIGH); }

        void redLightOn() { digitalWrite(rpin, LOW); digitalWrite(gpin, HIGH); digitalWrite(bpin, HIGH);}

        void off() { digitalWrite(pin, LOW); }

        void redLightOff() { digitalWrite(rpin, HIGH); digitalWrite(gpin, LOW); digitalWrite(bpin, LOW);}

        void clrRGBon(char color) {
            switch (color) {
                case 'r':
                    digitalWrite(rpin, LOW); 
                    digitalWrite(gpin, HIGH); 
                    digitalWrite(bpin, HIGH);
                    break;
                case 'g':
                    digitalWrite(rpin, HIGH); 
                    digitalWrite(gpin, LOW); 
                    digitalWrite(bpin, HIGH);
                    break;
                case 'b':
                    digitalWrite(rpin, HIGH); 
                    digitalWrite(gpin, HIGH); 
                    digitalWrite(bpin, LOW);
                    break;
                case 'w':
                    digitalWrite(rpin, LOW); 
                    digitalWrite(gpin, LOW); 
                    digitalWrite(bpin, LOW);
                    break;
                default:
                    Serial.print('che durak tak delat?');
                    break;
            }
        }

        void clrRGBoff(char color) {
            switch (color) {
                case 'r':
                    digitalWrite(rpin, HIGH); 
                    digitalWrite(gpin, LOW); 
                    digitalWrite(bpin, LOW);
                    break;
                case 'g':
                    digitalWrite(rpin, LOW); 
                    digitalWrite(gpin, HIGH); 
                    digitalWrite(bpin, LOW);
                    break;
                case 'b':
                    digitalWrite(rpin, LOW); 
                    digitalWrite(gpin, LOW); 
                    digitalWrite(bpin, HIGH);
                    break;
                case 'w':
                    digitalWrite(rpin, HIGH); 
                    digitalWrite(gpin, HIGH); 
                    digitalWrite(bpin, HIGH);
                    break;
                default:
                    Serial.print('che durak tak delat?');
                    break;
            }
        }


    private:
        int rpin;
        int gpin;
        int bpin;
        int pin;

};

void delay_s(unsigned int s) {
    delay(s * 1000); 
}