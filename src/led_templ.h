template<int pin>
class LED {
    public:

        LED() {};

        static void init() { pinMode(pin, OUTPUT); }
        static void on() { digitalWrite(pin, HIGH); }
        static void off() { digitalWrite(pin, LOW); }
}; // class

template<int pin, int rpin, int gpin, int bpin>
class RGB_LED {
    public:

        RGB_LED() {};

        static void init() { pinMode(pin, OUTPUT); pinMode(rpin, OUTPUT); pinMode(gpin, OUTPUT); pinMode(bpin, OUTPUT);}

        static void on() { digitalWrite(pin, HIGH); }

        static void redLightOn() { digitalWrite(rpin, LOW); digitalWrite(gpin, HIGH); digitalWrite(bpin, HIGH);}

        static void off() { digitalWrite(pin, LOW); }

        static void redLightOff() { digitalWrite(rpin, HIGH); digitalWrite(gpin, LOW); digitalWrite(bpin, LOW);}

        static void analogColor(unsigned int rVal, unsigned int gVal, unsigned int bVal) {
            analogWrite(rpin, rVal); 
            analogWrite(gpin, gVal); 
            analogWrite(bpin, bVal);
        }

        static void clrRGB(char color) {
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

        static void staticRGBlight (double s){
            unsigned int r = 255;
            unsigned int g = 0;
            unsigned int b = 0;
            analogColor(r, g, b);

            while(b != 255) {
                b += 1;
                analogColor(r, g, b);
                delay(s * 1000);
            }

            while(r != 0) {
                r -= 1;
                analogColor(r, g, b);
                delay(s * 1000);
            }

            while(g != 255) {
                g += 1;
                analogColor(r, g, b);
                delay(s * 1000);
            }

            while(b != 0) {
                b -= 1;
                analogColor(r, g, b);
                delay(s * 1000);
            }

            while(r != 255) {
                r += 1;
                analogColor(r, g, b);
                delay(s * 1000);
            }

            while(g != 0) {
                r -= 1;
                analogColor(r, g, b);
                delay(s * 1000);
            }
        }
        /*
        static void clrRGBoff(char color) {
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
            
        }*/
}; // class

void delay_s(unsigned int s){
    delay(s * 1000);
}